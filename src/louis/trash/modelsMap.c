#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <ncurses.h> // sudo apt-get install libncurses5-dev libncursesw5-dev  
#include "termcolor.h"



static const size_t min_buff = 10; // taille mininal
static const size_t taille = 1000; 
static const size_t largeur = 1000;
static const unsigned int deplacement = 1000;
static const unsigned int etapes = 2500;

static void usage(void) {
    puts("Usage:");
    puts("\tascii-owrpg [file]");
    puts("\tascii-owrpg -h");
}

struct world_s
{
    int taille; 
    int largeur;  
    int y_pos;  
    int x_pos;  
                    // rajouter tout les attributs du personage
    char** map;
};

typedef struct world_s world_t;

enum mouvement_e {
    UP,
    DOWN,
    LEFT,
    RIGHT
}; 

typedef enum mouvement_e mouvement_t;


void* malloc_p(size_t s){ //malloc protegé
  void *p;
  if(!(p = malloc(s))) {exit(EXIT_FAILURE);}

  return p;
}

world_t load_world(const char* f) {
    FILE* fp = fopen(f, "r");
    
    if (!fp) {
        perror("Error while reading file");
        exit(EXIT_FAILURE);
    }

    char* buf = malloc_p(sizeof(char) * min_buff);
    size_t buf_size = min_buff;
    size_t first_line_length;
    size_t current_line_length = 0;
    bool first_line = true;
    size_t line_number = 0;
    world_t new_world;
    new_world.map = NULL;
    bool player_already_found = false;
    char c;

    while((c = getc(fp)) != EOF) { // EOF = END OF FILE
        if (c == '\n') {
            if (first_line) {
                first_line_length = current_line_length;
                new_world.largeur = first_line_length;
                first_line = false;
            }
            else {
                if (current_line_length != first_line_length) {
                    fprintf(stderr, "Error: map is not square\n");
                    exit(EXIT_FAILURE);
                }
            }
            new_world.map = realloc(new_world.map, sizeof(char*) * (line_number + 1));
            new_world.map[line_number] = malloc_p(sizeof(char) * current_line_length);
            memcpy(new_world.map[line_number], buf, current_line_length + 1);
            line_number++;
            current_line_length = 0;
            free(buf);
            buf = malloc_p(sizeof(char) * min_buff);
            buf_size = min_buff;
            continue;
        }
        if ((c != '#') && (c != '.') && (c != '@')) { // on verifie que il n y pas de collision 
            fprintf(stderr, 
                "Unknown character \"%c\" in the data file \"%s\"\n at line %zu, column %zu\n", 
                    c, f, line_number+1, current_line_length+1);
            exit(EXIT_FAILURE);
        }
        if (c == '@') {
            if (player_already_found) {
                fprintf(stderr, "More than one player position found\n");
                exit(EXIT_FAILURE); 
            }
            new_world.x_pos = current_line_length;
            new_world.y_pos = line_number;
            c = '.';
            player_already_found = true;
        }
        if (buf_size <= current_line_length) {
            buf = realloc(buf, (buf_size + min_buff) * sizeof(char));
            buf_size += min_buff;
        }
        buf[current_line_length++] = c;
    }

    free(buf); // libere le buffer 

    if (!player_already_found) {
        fprintf(stderr, "No player was found on the map\n");
        exit(EXIT_FAILURE);
    }

    new_world.taille = line_number;
    
    if (!feof(fp)) {
        perror("Error while reading file");
        exit(EXIT_FAILURE);
    }

    fclose(fp); //ferme le fichier 



    return new_world;
}

world_t new_world(size_t taille, size_t largeur, size_t deplacement, size_t etapes) {
    srand(time(NULL));

    typedef struct { int y; int x; } coordinate_t;

    world_t new_world;
    new_world.taille = taille;
    new_world.largeur = largeur;

    char** new_map = NULL;
    for(size_t i = 0; i < taille; ++i) {
        new_map = realloc(new_map, sizeof(char*) * i + 1);
        new_map[i] = malloc_p(sizeof(char) * largeur);
        for(size_t j = 0; j < largeur; ++j) {
            new_map[i][j] = '#';
        }
    }
    int cmp = 0; // compteur
    coordinate_t* free_cells = malloc_p(sizeof(coordinate_t) * deplacement * etapes); // 
    for(int i = 0; i < deplacement; ++i) {
        int y, x;
        y = rand() % taille;
        x = rand() % largeur;
        for(int j = 0; j < etapes; ++j) {
            mouvement_t direction = rand() % 4;
            switch (direction) {
                case UP:
                    if ((y - 1) > 1) {
                        new_map[--y][x] = '.';
                        free_cells[cmp].y = y;
                        free_cells[cmp].x = x;
                        cmp++;
                    }
                    break;
                case RIGHT:
                    if ((x + 1) < largeur - 1) {
                        new_map[y][++x] = '.';
                        free_cells[cmp].y = y;
                        free_cells[cmp].x = x;
                        cmp++;
                    }
                    break;
                case LEFT:
                    if ((x - 1) > 1) {
                        new_map[y][--x] = '.';
                        free_cells[cmp].y = y;
                        free_cells[cmp].x = x;
                        cmp++;
                    }
                    break;
                case DOWN:
                    if ((y + 1) < taille - 1) {                     
                        new_map[++y][x] = '.';
                        free_cells[cmp].y = y;
                        free_cells[cmp].x = x;
                        cmp++;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    new_world.map = new_map;
    coordinate_t player = free_cells[rand() % cmp];
    new_world.y_pos = player.y;
    new_world.x_pos = player.x;
    free(free_cells);
    return new_world;
}

void draw_world(world_t* world, int row, int col) {
    size_t new_taille, new_largeur;
    new_taille = row > world->taille ? world->taille : row;
    new_largeur = col > world->largeur ? world->largeur : col;
    wresize(stdscr, new_taille, new_largeur);
    size_t player_pos_x, player_pos_y;
    size_t dist_to_right_edge = world->largeur - world->x_pos;
    size_t right_col;
    row = row;
    if (dist_to_right_edge < col / 2) {
        right_col = world->largeur;
    }
    else if (world->x_pos < col / 2) { // the same as dist to left edge
        right_col = col;
    }
    else {
        right_col = world->x_pos + col / 2;
    }
    size_t distance_coin_inferieur = world->taille - world->y_pos;
    size_t bottom_row;
    if (distance_coin_inferieur < row / 2) {
        bottom_row = world->taille;
    }
    else if (world->y_pos < row / 2) { // the same as dist to upper edge
        bottom_row = row;
    }
    else {
        bottom_row = world->y_pos + row / 2;
    }
    size_t left_col = right_col - (size_t)fmin(col, world->largeur);
    size_t upper_row = bottom_row - (size_t)fmin(row, world->taille);
    char* str = malloc_p(sizeof(char) * 
        (right_col - left_col) * (bottom_row - upper_row));
    int offset = 0;
    for (size_t i = upper_row; i < bottom_row; ++i) {
        for(size_t j = left_col; j < right_col; ++j) {
            if ((i == world->y_pos) && (j == world->x_pos)) {
                str[offset + j - left_col] = '@';    
            }
            else {
                str[offset + j - left_col] = world->map[i][j];
            }
        }
        offset+=(right_col - left_col);
    }
    printw(str);
    free(str);
}


void attaque(); // proto

void utiliser_un_objet(); // proto

void move_character(mouvement_t mvt, world_t* world) {
    switch (mvt) {
        case UP:
            if (world->y_pos - 1 < 0) {
                break;
            }
            if (world->map[world->y_pos - 1][world->x_pos] != '#') {
                world->y_pos--;
            }
            break;
        case DOWN:
            if (world->y_pos + 1 >= world->taille) {
                break;
            }
            if (world->map[world->y_pos + 1][world->x_pos] != '#') {
                world->y_pos++;
            }
            break;
        case RIGHT:
            if (world->x_pos + 1 >= world->largeur) {
                break;
            }
            if (world->map[world->y_pos][world->x_pos + 1] != '#') {
                world->x_pos++;
            }
            break;
        case LEFT:
            if (world->x_pos - 1 < 0) {
                break;
            }
            if (world->map[world->y_pos][world->x_pos - 1] != '#') {
                world->x_pos--;
            }
            break;
        default:
            break;
    }
}

int main(int argc, char* argv[]) {
    if (argc > 2) {
        usage();
        exit(EXIT_FAILURE);
    }
    if ((argc == 2) && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
        usage();
        exit(EXIT_SUCCESS);
    }

    world_t world;

    if (argc == 2) {
        world = load_world(argv[1]);
    }
    else {
        world = new_world(taille, largeur, deplacement, etapes);
    }

	initscr();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);

    int row, col;
    int c;

	while (1) {
		clear();
        getmaxyx(stdscr, row, col);
        draw_world(&world, row, col);
		refresh();
		c = getch();
        switch(c) {
            case KEY_UP:
            case 'w':
            case 'k':
                move_character(UP, &world);
                break;
            case KEY_DOWN:
            case 's':
            case 'j':
                move_character(DOWN, &world);
                break;
            case KEY_RIGHT:
            case 'd':
            case 'l':
                move_character(RIGHT, &world);
                break;
            case KEY_LEFT:
            case 'a':
            case 'h':
                move_character(LEFT, &world);
                break;
            default:
                break;
        }
	}
	endwin();
}