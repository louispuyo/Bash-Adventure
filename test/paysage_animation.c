#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#pragma comment (lib,"sdl.lib")      // ignorez ces lignes si vous ne linkez pas les libs de cette façon.
#pragma comment (lib,"sdlmain.lib")

#define LARGEUR_TILE 24  // hauteur et largeur des tiles.
#define HAUTEUR_TILE 16 

#define NOMBRE_BLOCS_LARGEUR 15  // nombre a afficher en x et y
#define NOMBRE_BLOCS_HAUTEUR 13

char* table[] = {
"000000000000000",
"000000000000000",
"000000000000000",
"000000000000000",
"100000000111110",
"000000000000000",
"000000000000000",
"000000000000000",
"003400022220022",
"005600000000000",
"005600000000000",
"005600000000000",
"777777777777777"};


void Afficher(SDL_Surface* screen,SDL_Surface* tileset,char** table,int nombre_blocs_largeur,int nombre_blocs_hauteur)
{
	int i,j;
	SDL_Rect Rect_dest;
	SDL_Rect Rect_source;
	Rect_source.w = LARGEUR_TILE;
	Rect_source.h = HAUTEUR_TILE;
	for(i=0;i<nombre_blocs_largeur;i++)
	{
		for(j=0;j<nombre_blocs_hauteur;j++)
		{
			Rect_dest.x = i*LARGEUR_TILE;
			Rect_dest.y = j*HAUTEUR_TILE;
			Rect_source.x = (table[j][i]-'0')*LARGEUR_TILE;
			Rect_source.y = 0;
			SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
		}
	}
	
}

int main(int argc,char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

 SDL_Window* window = SDL_CreateWindow("Animating using Sprite Sheets", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);	

	SDL_Surface* screen,*tileset;
	SDL_Event event;
    SDL_Texture* spriteSheet = NULL;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* temp = IMG_Load("../res/img/sprite.png");
    spriteSheet = SDL_CreateTextureFromSurface(renderer, temp);
    tileset = SDL_LoadBMP("tileset1.bmp");
	if (!tileset)
	{
		printf("Echec de chargement tileset1.bmp\n");
		SDL_Quit();
		
		exit(-1);
	}
	Afficher(spriteSheet, tileset,table,NOMBRE_BLOCS_LARGEUR,NOMBRE_BLOCS_HAUTEUR);

	do  // attend qu'on appuie sur une touche.
	{
		SDL_WaitEvent(&event);
	} while (event.type!=SDL_KEYDOWN);
	
	SDL_FreeSurface(tileset);
	SDL_Quit();
	return 0;
}