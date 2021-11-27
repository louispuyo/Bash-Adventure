//
// Created by admin on 24/11/2021.
//
//INCLUDE--------------------------------------------------------------------//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "entity.h"
#include "mob.h"
#include "actions.h"
#include "player.h"
#include "inventaire.h"
#include "item.h"
//INITIALISATION-------------------------------------------------------------//
void initialisation(){
    Entity *e,*e2;
    initEnt(&e);
    *e=selectionP();
    initWolf(&e2);
    battlePhase(&e,&e2);
}
//---------------------------------------------------------------------------//
int main() {
    printf("Hello, World!\n");
    initialisation();
    return 0;
}

