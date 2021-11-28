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
    initSlime(&e2);
    battlePhase(&e,&e2);

//    Inventaire *inventaire;
//    creationInvent(&inventaire);
//    ajoutFinInventaire(inventaire,InitSword());
//    afficheItem(chercherItem(inventaire,"GALATINE"),1,1);

//    Item *item;
//    initItem(&item);
//    modItemName(&item,"LH");
//    afficheItem(item);
////
//    afficheInvent(e->inventaire);
////    afficheItem(ItemSword(&e));
//    afficheInvent(e->inventaire);
//    printf("PAUSE\n");
//    Item *item;
//    initItemSword(&item);
//    modItemName(&item,"Epee");
//    ajoutFinInventaire(e->inventaire,item);
//    afficheInvent(e->inventaire);
}
//---------------------------------------------------------------------------//
int main() {
    printf("Hello, World!\n");
    initialisation();
    return 0;
}

