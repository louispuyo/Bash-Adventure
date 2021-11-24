//
// Created by Julio on 24/11/2021.
//

#ifndef BASH_ADVENTURE_ITEM_H
#define BASH_ADVENTURE_ITEM_H
//INCLUDE----------------------------------------------------------------//
#include "main.h"
//--------------------------------------------------------------------------//
//CONSTANTES----------------------------------------------------------------//
#define char *poids[3]{"zero","leger","moyen","lourd"};//constantes des poids
//--------------------------------------------------------------------------//
typedef struct Item Item;//Struct Item
struct Item {
    char *nom;//nom de l'Item
    char *des;//description de l'Item
    int *place;//niveau d'encombrement de l'item 1=léger 2=moyen 3=lourd
    int (*options);
    Item *suivant;
};

//POUR ITEM-----------------------------------------------------------------//
//<fonction qui affiche> simple pointeur "void func(*args){}"
//<fonction qui agit> double pointeur "void func(**args){}"
//<fonction qui sert d'option> pointeur de fonction "(*option)(*args)"
// "void (*func)(*args){}"

//fonction pour initaliser
void initIt(Item **pItem){
    if(!(*pItem=(Item*) malloc(sizeof(Item)))){ exit(-1);}
    (*pItem)->nom     = 0;
    (*pItem)->des     = 0;
    (*pItem)->place   = 0;
    (*pItem)->options = 0;
    (*pItem)->suivant = NULL;
}
//fonction pour ajouter au debut
//fonction pour ajouter a la fin
//fonction pour afficher
//fonction pour supprimer au debut
//fonction pour supprimer a la fin
//fonction pour retrouver
//fonction pour trier alphabetiquement (si vous etes chaud)
//fonction pour modifier
//--------------------------------------------------------------------------//
#endif //BASH_ADVENTURE_ITEM_H
