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
#include "unistd.h"
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
#define SOINS char* s[1]={"SOINS"};
//POUR ACTIONS---------------------------------------------------------------//
/// Une attaque d'une entité a une autre
/// \param from
/// \param to
void EntAttack(Entity *from,Entity **to,int itemUSe){
    printf(">>>\"%s\" ATTAQUE \"%s\"\n",from->nom,(*to)->nom);//attention au
    // printf
    (*to)->pv-=from->atk+itemUSe-(*to)->def;
    printf(">>>\"%s\" A FAIT %d DEGATS\n",(*from).nom,(from->atk+itemUSe-(*to)
    ->def));
    printf(">>>\"%s\" PERDS %d PV\n",(*to)->nom,(from->atk)+itemUSe-(*to)->def);
    printf(">>>\"%s\" A MAINTENANT %d PV\n",(*to)->nom,(*to)->pv);
}

void utilSoin(Entity **pEntity,Item *pItem){
    (*pEntity)->pv += pItem->DEG;
    printf("%s RECUPERE %d PV",(*pEntity)->nom,pItem->DEG);
}
//MENU ATTAQUE---------------------------------------------------------------//
void menuAttack(Entity **e1,Entity **e2,int i){
    switch (i) {
        case 1:
            EntAttack(*e1,e2,0);
            break;
        case 2:
            afficheInvent((*e1)->inventaire);
            printf("QUE FAIRE?\n"
                   "\t1:Utiliser\n"
                   "\t2:Retour\n");
            int choix;
            scanf("%d",&choix);
            if(choix==2){break;}
            int itemC = 0;//Ce bout de code pourrait etre dans une fonction
            printf("SELECTIONNER SLOT>>>");
            scanf("%d",&itemC);
            printf(">>>\"%s\" UTILISE %s\n",(*e1)->nom,chercherItemInt((*e1)
            ->inventaire,itemC)->nom);
            if(strcmp(chercherItemInt((*e1)->inventaire, itemC)->des,"SOINS")
            == 0 ){
                utilSoin(e1,chercherItemInt((*e1)->inventaire, itemC));
            } else{
                EntAttack(*e1,e2,chercherItemInt((*e1)->inventaire,itemC)->DEG);
            }
            i =1;
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
    char* bim[3]={"bim","bam","boum"};
    printf("DEBUT DU COMBAT\n");
    printf("\"%s\" CONTRE %s\n",(*e1)->nom,(*e2)->nom);
    affIt(*e2,1,0);
    while ((*e1)->pv>0 && ((*e2)->pv>0) && i!=3){
        printf("QUE FAIRE?\n"
               "1:ATTAQUER\n"
               "2:INVENTAIRE\n"
               "3:FUIR\n");
        scanf("%d",&i);
        if(i==3){ printf("\"%s\" EST UN LACHE MAIS UN LACHE VIVANT\n",
                         (*e1)->nom);break;}
        menuAttack(e1,e2,i);
        if((*e2)->pv > 0){
            printf("\n<<<L'ENNEMI RIPOSTE>>>\n");
            for (int j = 0; j < 3; ++j) {
                printf("%s.",bim[j]);
                sleep(1);
            }printf("\n");
            EntAttack(*e2,e1,0);
        }
    }
    if((*e1)->pv>=1&&i!=3){
        printf("<<<\"%s\" A VAINCU \"%s\">>>\n",(*e1)->nom,(*e2)->nom);
        loot(e2,e1);
        if((*e1)->xp>=2){ lvlUp(e1); };
        return (*e1);
    }
    else{
        printf("<<<\"%s\" A VAINCU \"%s\">>>\n",(*e2)->nom,(*e1)->nom);
        return (*e2);
    }

}
//--------------------------------------------------------------------------//

#endif //BASH_ADVENTURE_ACTIONS_H
