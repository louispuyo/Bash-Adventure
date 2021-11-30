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

void test (){
//    Monde *monde;
//    Entity *entity,*e2;
//    creationMonde(&monde);
//    initWolf(&entity);
//    initBandit(&e2);
//    ajoutFinMonde(monde,entity);
//    ajoutFinMonde(monde,e2);
//    afficheMonde(monde);
//    supprimeValListe(monde,e2->pos);
//    supprimeValListe(monde,entity->pos);
//    afficheMonde(monde);
//    system("PAUSE");
    Inventaire *inventaire;
    creationInvent(&inventaire);
    ajoutFinInventaire(inventaire,InitSoin());
    afficheInvent(inventaire);
    system("PAUSE");
}
//---------------------------------------------------------------------------//
int main() {
    printf("Hello, World!\n");
    //initialisation();
    test();
    return 0;
}


