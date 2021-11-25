/*
    Louis : 25/11/2021 : bot.h 
    description : fichier definissant le comportement des bots dans le jeu 



    
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
#include <math.h>
#include "utils.h"
#include "../julio/entity.h"
#include "../julio/player.h"
#define _MEMORY_SIZE_ 40



// PROTOTYPE SI ON A LE TEMPS // 
typedef struct 
{
    float input;
    float output;

    /* data */
} Node;


typedef struct 
{
    Node *List[_MEMORY_SIZE_];


} Network;


// FIN PROTOTYPE

// ACTION POSSIBLE

enum actions_liste { // poids de probabilitee de chaques actions du bot
    droite = 0,
    gauche = 0,
    haut = 0,
    bas = 0,
    attaque = 0 ,
    defense = 0 

};

// typedef struct{
//     int score;
//     int weight;
//     int *id;
// } Action;



typedef struct {
    Entity base; // base 
    int pos_x;
    int pos_y;
    double score;
   
    

    

} Bot;

void initialisation_actions(Bot bot); // attribut les poids pour chaque action


void deplacement(Bot* bot);


int main(int argc, char const *argv[])
{   
    Bot *bot;
    
    
    
    

    return 0;
}
