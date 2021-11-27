//
// Created by Julio on 24/11/2021.
//

#ifndef BASH_ADVENTURE_PLAYER_H
#define BASH_ADVENTURE_PLAYER_H
//INCLUDE-------------------------------------------------------------------//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include <ctype.h>  //<-- You need this to use toupper() function.
#include "entity.h"
//--------------------------------------------------------------------------//
void funcUp(char **name) {
    (*name) = strdup(*name); // make a copy of name
    for (char *p = (*name); *p; p++) {
        *p = toupper(*p);
    }
}
//CONSTANTES----------------------------------------------------------------//
#define VIE_MIN int 0;
#define VIE_MAX ;
#define XP_MIN int 0;
#define XP_MAX int 100;
#define LVL_MIN int 0;
#define LVL_MAX int 100;
#define MONEY_MIN int 0;
#define MONEY_MAX int 100;
//POUR PLAYER---------------------------------------------------------------//
/// Initialise un Mob de type Slime
/// \param pEntity
void initWarrior(Entity **pEntity){
    initEnt(pEntity);
    modItName(pEntity,"\"Jean\"");
    modItDes(pEntity,"\"CHEVALIER\"");//par exemple
    modItPv(pEntity,10);
    modItPvMax(pEntity,10);
    modItXp(pEntity,0);
    modItLvl(pEntity, 1);
    modItMoney(pEntity,5);
    modItAtk(pEntity,2);
    modItDef(pEntity,2);

}
/// Initialise un Mob de type Lezard
/// \param pEntity
void initWizard(Entity **pEntity){
    initEnt(pEntity);
    modItName(pEntity,"\"Harry\"");
    modItDes(pEntity,"\"MAGE\"");
    modItPv(pEntity,10);
    modItPvMax(pEntity,10);
    modItXp(pEntity,0);
    modItLvl(pEntity, 1);
    modItMoney(pEntity,4);
    modItAtk(pEntity,3);
    modItDef(pEntity,1);
}
/// Initialise un Mob de type Loup
/// \param pEntity
void initBandit(Entity **pEntity){
    initEnt(pEntity);
    modItName(pEntity,"\"Rinaldo\"");
    modItDes(pEntity,"\"BANDIT\"");
    modItPv(pEntity,10);
    modItPvMax(pEntity,10);
    modItXp(pEntity,0);
    modItLvl(pEntity, 1);
    modItMoney(pEntity,6);
    modItAtk(pEntity,3);
    modItDef(pEntity,0);
}
char* stats(int i){

}
//CHOIX CLASSE DUJOUEUR-----------------------------------------------------//
 Entity selectionP(){
    char *pName= (char *)malloc(sizeof(char ));
    int choix[]={1,2,3};
    int i=0;
    printf("VOTRE NOM?\n");
    scanf("%s",pName);funcUp(&pName);
    do {
        printf("%s CHOISSISEZ VOTRE CLASSE IL Y A 3 CLASSES\n"
               "    [1]:CHEVALIER\n"
               "    [2]:MAGE\n"
               "    [3]:BANDIT\n",pName);
        scanf("%d",&i);
        if(i<1 || i>3){ printf("Inccorect\n");}
    } while (i<1 || i>3);
    Entity *entity;
    switch (i) {
        case 1:
            initWarrior(&entity);
            modItName(&entity,pName);
            affIt(entity,1,1);
            break;
        case 2:
            initWizard(&entity);
            modItName(&entity,pName);
            affIt(entity,1,1);
            break;
        case 3:
            initBandit(&entity);
            modItName(&entity,pName);
            affIt(entity,1,1);
            break;
        default:
            break;
    }
    printf("START GAME\n");
}
//--------------------------------------------------------------------------//
#endif //BASH_ADVENTURE_PLAYER_H
