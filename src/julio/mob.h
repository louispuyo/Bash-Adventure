//
// Created by Julio on 24/11/2021.
//

#ifndef BASH_ADVENTURE_MOB_H
#define BASH_ADVENTURE_MOB_H
//INCLUDE-------------------------------------------------------------------//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
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
//POUR MOB------------------------------------------------------------------//
/// Initialise un Mob de type Slime
/// \param pEntity
void initSlime(Entity **pEntity){
    initEnt(pEntity);
    modItName(pEntity,"\"Slime\"");
    modItDes(pEntity,"\"Full of goo\"");
    modItPv(pEntity,5);
    modItPvMax(pEntity,5);
    modItXp(pEntity,1);
    modItLvl(pEntity, 1);
    modItMoney(pEntity,0);
    modItAtk(pEntity,1);
    modItDef(pEntity,0);


}
/// Initialise un Mob de type Lezard
/// \param pEntity
void initLizard(Entity **pEntity){
    initEnt(pEntity);
    modItName(pEntity,"\"Lizard\"");
    modItDes(pEntity,"\"Full of scales\"");
    modItPv(pEntity,5);
    modItPvMax(pEntity,5);
    modItXp(pEntity,1*2);
    modItLvl(pEntity, 1*2);
    modItMoney(pEntity,2);
    modItAtk(pEntity,1*2);
    modItDef(pEntity,1);
}
/// Initialise un Mob de type Loup
/// \param pEntity
void initWolf(Entity **pEntity){
    initEnt(pEntity);
    modItName(pEntity,"\"Wolf\"");
    modItDes(pEntity,"\"Full of furr\"");
    modItPv(pEntity,5*3);
    modItPvMax(pEntity,5*3);
    modItXp(pEntity,1*3);
    modItLvl(pEntity, 1*3);
    modItMoney(pEntity,3);
    modItAtk(pEntity,1*3);
    modItDef(pEntity,0);
}
//--------------------------------------------------------------------------//
#endif //BASH_ADVENTURE_MOB_H
