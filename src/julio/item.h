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
    int poids;//niveau d'encombrement de l'item 1=léger 2=moyen 3=lourd
    void (*funcItem)(int i);//pointeur sur
    // fonction
    int DEG;//Dégats de l'item
    int pos;//position de l'item
    Item *suivant;
};
//CONSTANTES----------------------------------------------------------------//
#define poid [3]{"zero","leger","moyen","lourd"};//constantes des poids
//MENU UTILISATION----------------------------------------------------------//
void menuIte(int i){
    switch (i) {
        case 1:
            printf("Utiliser\n");

            break;
        case 2:
            printf("Donner\n");
            break;
        case 3:
            printf("Lacher\n");
            break;
        case 4:
            printf("\n");
            break;
        default:
            printf("Somehow you fucked up...\n");//A CHANGER
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
    (*pItem)->poids   = 0;
    (*pItem)->DEG   = 0;
    (*pItem)->pos = 0;
    (*pItem)->suivant = NULL;
    (*pItem)->funcItem = menuIte;
//    printf("InitItem\n");
}

//fonction pour ajouter au debut

//fonction pour ajouter a la fin

//fonction pour afficher
void afficheItem(Item *item,int i,int full){
    printf("\t<<<ITEM");
    if(i>=0) {
        if (full==1)printf("\titem->slot : ");
        printf("\tSLOT %d\n", item->pos);
        if (full==1)printf("\titem->nom : ");
        printf("\t%s\n", item->nom);
        if (full==1)printf("\titem->des : ");
        printf("\t%s\n", item->des);
        if (full==1)printf("\titem->place : ");
        printf("\t%d KG\n", item->poids);
        if(strcmp(item->des,"SOINS") == 0 ){
            if (full==1)printf("\titem->SOINS : ");
            printf("\t+ %d VIE\n", item->DEG);
        } else{
            if (full==1)printf("\titem->DEGATS : ");
            printf("\t+ %d ATK\n", item->DEG);
        }
        //if(item->suivant){ printf("suivant : %s\n",item->suivant->nom);}
    }
}
//fonction pour supprimer au debut
//fonction pour supprimer a la fin
//fonction pour retrouver

//fonction pour trier alphabetiquement (si vous etes chaud)
///fonction pour modifier le nom de l'item
/// \param pItem
/// \param ptr
void modItemName(Item **pItem,char *ptr){
    (*pItem)->nom = ptr;
}

void modItemDes(Item **pItem,char *ptr){
    (*pItem)->des = ptr;
}

void modItemPoids(Item **pItem, int i){
    (*pItem)->poids = i;
}
void modItemDeg(Item **pItem,int i){
    (*pItem)->DEG = i;
}

//ITEMS DU JEU---------------------------------------------------------------//
Item* InitSword(){
    Item *pItem;
    initItem(&pItem);
    modItemName(&pItem,"GALATINE");
    modItemDes(&pItem,"EPEE");
    modItemPoids(&pItem, 2);
    modItemDeg(&pItem,2);
}

Item* InitWaterMagic(){
    Item *pItem;
    initItem(&pItem);
    modItemName(&pItem,"SPLASHARUS");
    modItemDes(&pItem,"MAGIE");
    modItemPoids(&pItem, 0);
    modItemDeg(&pItem,2);
}
Item* InitKnife(){
    Item *pItem;
    initItem(&pItem);
    modItemName(&pItem,"APAIN");
    modItemDes(&pItem,"COUTEAU");
    modItemPoids(&pItem, 1);
    modItemDeg(&pItem,1);
}

Item* InitRage(){
    Item *pItem;
    initItem(&pItem);
    modItemName(&pItem,"RAGE");
    modItemDes(&pItem,"OMBRE");
    modItemPoids(&pItem, 2);
    modItemDeg(&pItem,0);
}

Item* InitSoin(){
    Item *pItem;
    initItem(&pItem);
    modItemName(&pItem,"POTION");
    modItemDes(&pItem,"SOINS");
    modItemPoids(&pItem, 1);
    modItemDeg(&pItem,2);
}
//POINTEUR SUR FONCTION------------------------------------------------------//
///Fonction qui appelle un pointeur de fonction pour utiliser l'item
/// \param pItem//A REVOIR
void choixIt(Item **pItem) {
    int i;
    printf("Choix...[1:4]\n");
    scanf("%d",&i);
    (*pItem)->funcItem(i);
}
//--------------------------------------------------------------------------//
#endif //BASH_ADVENTURE_ITEM_H
