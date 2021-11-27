//
// Created by Julio on 24/11/2021.
//

#ifndef BASH_ADVENTURE_ACTIONS_H
#define BASH_ADVENTURE_ACTIONS_H
//INCLUDE-------------------------------------------------------------------//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
//#elif defined(BASH_ADVENTURE_ACTIONS_H)
#include "entity.h"
//--------------------------------------------------------------------------//
//CONSTANTES----------------------------------------------------------------//
#define VIE_MIN int 0;
#define VIE_MAX ;
#define XP_MIN int 0;
#define XP_MAX int 100;
#define LVL_MIN int 0;
#define LVL_MAX int 100;
#define MONEY_MIN int 0;
#define MONEY_MAX int 100;
//POUR ACTIONS---------------------------------------------------------------//
/// Une attaque d'une entité a une autre
/// \param from
/// \param to
void EntAttack(Entity *from,Entity**to){
    printf("%s attack %s\n",from->nom,(*to)->nom);//attention au printf
    (*to)->pv-=from->atk;
    printf("%s lost %d pv\n",(*to)->nom,(from->atk));
}
//MENU ATTAQUE---------------------------------------------------------------//
void menuAttack(int i){
    switch (i) {
        case 1:
            printf("Op1");
            break;
        case 2:
            printf("Op2");
            break;
        case 3:
            printf("Op3");
            break;
        case 4:
            printf("Op4");
            break;
        default:
            break;
    }
}
//--------------------------------------------------------------------------//
void choixAtk(Entity **pEntity){
    int i;
    printf("Choix...[1:4]\n");
    scanf("%d",&i);
    (*pEntity)->funcInter(i);
}
//BATTLE PHASE---------------------------------------------------------------//
void battlePhase(Entity **e1,Entity **e2){
    printf("DEBUT DU COMBAT\n");
    printf("%s CONTRE %s",(*e1)->nom,(*e2)->nom);
    affIt(*e1,1,0);
    printf("QUE FAIRE?");
}
//--------------------------------------------------------------------------//

#endif //BASH_ADVENTURE_ACTIONS_H
