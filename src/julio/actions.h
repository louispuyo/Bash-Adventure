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
void EntAttack(Entity *from,Entity **to){
    printf("%s attack %s\n",from->nom,(*to)->nom);//attention au printf
    (*to)->pv-=from->atk-(*to)->def;
    printf("%s A FAIT %d DEGATS\n",(*from).nom,(from->atk-(*to)->def));
    printf("%s PERDS %d PV\n",(*to)->nom,(from->atk)-(*to)->def);
    printf("%s A MAINTENANT %d PV\n",(*to)->nom,(*to)->pv);
}

void utilItem(Entity **e){
    afficheInvent((*e)->inventaire);
}
//MENU ATTAQUE---------------------------------------------------------------//
void menuAttack(Entity **e1,Entity **e2,int i){
    switch (i) {
        case 1:
            EntAttack(*e1,e2);
            break;
        case 2:
            afficheInvent((*e1)->inventaire);
            break;
        case 3:
            printf("FUITE\n");
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
///BATTLE PHASE---------------------------------------------------------------//
/// Phase de combat entre deux entitées
/// \param e1
/// \param e2
/// \return Entity
Entity* battlePhase(Entity **e1,Entity **e2){
    int i;
    printf("DEBUT DU COMBAT\n");
    printf("%s CONTRE %s\n",(*e1)->nom,(*e2)->nom);
    affIt(*e2,1,0);
    while ((*e1)->pv>0 && ((*e2)->pv>0) && i!=3){
        printf("QUE FAIRE?\n"
               "1:ATTAQUER\n"
               "2:INVENTAIRE\n"
               "3:FUIR\n");
        scanf("%d",&i);
        if(i==3){ printf("%s EST UN LACHE MAIS UN LACHE VIVANT\n",
                         (*e1)->nom);break;}
        menuAttack(e1,e2,i);
    }
    if((*e1)->pv>=1&&i!=3){
        printf("%s A VAINCU %s",(*e1)->nom,(*e2)->nom);
        return (*e1);
    }
    else{
        printf("%s A VAINCU %s",(*e2)->nom,(*e1)->nom);
        return (*e2);
    }
}
//--------------------------------------------------------------------------//

#endif //BASH_ADVENTURE_ACTIONS_H
