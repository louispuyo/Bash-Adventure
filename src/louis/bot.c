/*
    Louis : 25/11/2021 : Entity.h 
    description : fichier definissant le comportement des Entitys dans le jeu 



    
*/



/*

initialiser Q[s, a] pour tout état s, toute action a de façon arbitraire, mais Q(état terminal, a) = 0 pour toute action a

répéter
      //début d'un épisode 
      initialiser l'état s
      
      répéter
               //étape d'un épisode
               choisir une action a depuis s en utilisant la politique spécifiée par Q (par exemple ε-greedy)
               exécuter l'action a
               observer la récompense r et l'état s'

               Q[s, a] := Q[s, a] + α[r + γ maxa' Q(s', a') - Q(s, a)]

               s := s'
               a := a'
      jusqu'à ce que s soit l'état terminal

*/

#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#include <unistd.h>
#include "utils.h"

#include "../julio/player.h"
#include "../julio/entity.h"
#include "../julio/player.h"
#include "../julio/mob.h"
#define _MEMORY_SIZE_ 40
#define symbole "@"
#define player_symbole "A"


#define couleur(param) printf("\033[%sm",param)




typedef struct {
    Entity base; // base 

    double score;
    Action *list_action;

} Player;


typedef struct { int y; int x; } Coords;




void initialisation_actions(Entity entity); // attribut les poids pour chaque action


void deplacement(Entity* entity)
{
int largeur = 30;




for(int j=0; j<20; j++){
    printf("\n");

for(int i=0; i<largeur; i++){
    
    if (i== entity->pos_x && j == entity->pos_y) 
    {
        printf("%s", symbole);
        

    }
    else{
       

    printf("%s", ".");
    
    }
    
    
}
}

}


void deplacement_du_bot(Entity *bot)
{
      int x = bot->pos_x + bot->speed_x;
      int y = bot->pos_y + bot->speed_y;
      modItPos(&bot, x, y);
      printf("%d %d \n\n",x,y );
     
}

int beta (Entity *entity)

{
           int *decision;


          
         
       while (*decision != 0)
    {

     
    
    deplacement(entity);
    deplacement_du_bot(entity);
    scanf("%d", decision);
    system("clear");
    menuInter(*decision);
    
  

    }
    
    
    return 0;
        
	}


  
    
    






int main() {

    Entity *entity;
    
    initEnt(&entity);
    modItSpeed(&entity, 1, 1);
    modItPos(&entity, 3, 3);
 


	beta(entity);
    
	return EXIT_SUCCESS;
}