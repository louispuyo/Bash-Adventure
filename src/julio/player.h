//
// Created by Julio on 24/11/2021.
//

#ifndef BASH_ADVENTURE_PLAYER_H
#define BASH_ADVENTURE_PLAYER_H
//INCLUDE-------------------------------------------------------------------//
#include "main.h"
#elif defined(BASH_ADVENTURE_PLAYER_H)
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
void initWarrior(Entity **pEntity){
    initIt(pEntity);
    modItName(pEntity,"\"Jean\"");
    modItDes(pEntity,"\"Warrior\"");//par exemple
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
    initIt(pEntity);
    modItName(pEntity,"\"Harry\"");
    modItDes(pEntity,"\"Wizard\"");
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
    initIt(pEntity);
    modItName(pEntity,"\"Rinaldo\"");
    modItDes(pEntity,"\"Bandit\"");
    modItPv(pEntity,10);
    modItPvMax(pEntity,10);
    modItXp(pEntity,0);
    modItLvl(pEntity, 1);
    modItMoney(pEntity,6);
    modItAtk(pEntity,3);
    modItDef(pEntity,0);
}
//--------------------------------------------------------------------------//
#endif //BASH_ADVENTURE_PLAYER_H
