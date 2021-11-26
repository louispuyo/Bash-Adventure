#include <stdio.h>
#include <stdlib.h>
#include "../src/julio/entity.h"

#define nombre_actions 6

char *action_list[nombre_actions] =  {  "droite",     "gauche",     "haut",     "bas",     "attaque", 
    "defense" };
     // poids de probabilitee de chaques actions du bot
  


typedef struct 
{
int score;
float weight;
int id;

}Action;


typedef struct 
{
    Entity core;
    Action derniere_action; // => affect la proba de cette action
    

    // derniere action
    // pv
    // xp
    // attack & player.attack
    // defense & player.defense
    
}Etat;






void initAction(Action *action){
action->id = 0;
action->score = 0;
action->weight = 1./nombre_actions;

}

// void change_weight(Bot bot);




int main(int argc, char const *argv[])
{
    Action *list_action = malloc((nombre_actions*sizeof(Action*))); 
    for (int i=0; i<nombre_actions; i++)
    {
        initAction(&list_action[i]);
        list_action[i].id = i;
        printf("%s\n", action_list[i]);
    }

    
    return 0;
}


