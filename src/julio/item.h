//
// Created by Julio on 24/11/2021.
//

#ifndef BASH_ADVENTURE_ITEM_H
#define BASH_ADVENTURE_ITEM_H
//INCLUDE----------------------------------------------------------------//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
//--------------------------------------------------------------------------//
typedef struct Item Item;//Struct Item
struct Item {
    char *nom;//nom de l'Item
    char *des;//description de l'Item
    int *place;//niveau d'encombrement de l'item 1=léger 2=moyen 3=lourd
    void (*funcItem)(int);//pointeur sur fonction
    Item *suivant;
};
//CONSTANTES----------------------------------------------------------------//
#define char *poids[3]{"zero","leger","moyen","lourd"};//constantes des poids
//--------------------------------------------------------------------------//
//MENU UTILISATION----------------------------------------------------------//
void menuIte(int i){
    switch (i) {
        case 1:
            printf("Utiliser");
            break;
        case 2:
            printf("Donner");
            break;
        case 3:
            printf("Lacher");
            break;
        case 4:
            printf("Détruire");
            break;
        default:
            printf("Somehow you fucked up...");//A CHANGER
            break;
    }
}
//--------------------------------------------------------------------------//
//POUR ITEM-----------------------------------------------------------------//
//<fonction qui affiche> simple pointeur "void func(*args){}"
//<fonction qui agit> double pointeur "void func(**args){}"
//<fonction qui sert d'option> pointeur de fonction "(*option)(*args)"
// "void (*func)(*args){}"

//fonction pour initaliser
void initItem(Item **pItem){
    if(!(*pItem=(Item*) malloc(sizeof(Item)))){ exit(-1);}
    (*pItem)->nom     = 0;
    (*pItem)->des     = 0;
    (*pItem)->place   = 0;
    (*pItem)->suivant = NULL;
    (*pItem)->funcItem = menuIte;
    printf("InitItem\n");
}
//fonction pour ajouter au debut
//fonction pour ajouter a la fin
//fonction pour afficher
//fonction pour supprimer au debut
//fonction pour supprimer a la fin
//fonction pour retrouver
//fonction pour trier alphabetiquement (si vous etes chaud)
//fonction pour modifier

//POINTEUR SUR FONCTION------------------------------------------------------//
///Fonction qui appelle un pointeur de fonction pour utiliser l'item
/// \param pItem
void choixIt(Item **pItem){
    int i;
    printf("Choix...[1:4]\n");
    scanf("%d",&i);
    (*pItem)->funcItem(i);
}
//--------------------------------------------------------------------------//
#endif //BASH_ADVENTURE_ITEM_H
