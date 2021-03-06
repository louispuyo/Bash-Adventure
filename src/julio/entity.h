//
// Created by Julio on 24/11/2021.
/*Header de création d'entité
 */
//

#ifndef BASH_ADVENTURE_ENTITY_H
#define BASH_ADVENTURE_ENTITY_H
//INCLUDE----------------------------------------------------------------//
#include "stdlib.h"
#include "ncurses.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "inventaire.h"
//--------------------------------------------------------------------------//
typedef struct Entity Entity;//Struct Entity
struct Entity {
    char *nom;//nom de l'Entity
    char *des;//description de l'Entity
    int pv;//points de vie
    int pvMax;//pv max
    int xp;//point d'experience
    int level;//niveau
    int money;//argent
    int atk;//dommages
    int def;//defense
    int pos_x;//position sur la map
    int pos_y;
    int pos;//position dans le monde
    int speed_x;
    int speed_y;

    Inventaire *inventaire;
    void (*funcInter)(int);//pointeur sur fonction

    Entity *suivant;
};
//CONSTANTES----------------------------------------------------------------//
#define VIE_MIN int 0;
#define VIE_MAX ;
#define XP_MIN int 0;
#define XP_MAX int 100;
#define LVL_MIN int 0;
#define LVL_MAX int 100;
#define MONEY_MIN int 0;
#define MONEY_MAX int 100;
#define INV_MAX int 5;
//--------------------------------------------------------------------------//

//POUR ENTITY----------------------------------------------------------------//
//<fonction qui affiche> simple pointeur "void func(*args){}"
//<fonction qui agit> double pointeur "void func(**args){}"
//<fonction qui sert d'option> pointeur de fonction "(*option)(*args)"
// "void (*func)(*args){}"


//fonction d'interaction
//MENU INTERACTIONS----------------------------------------------------------//
void menuInter(int i){
    switch (i) {
        case 1:
            printf("Attaquer\n");

            break;
        case 2:
            printf("Objet\n");
            break;
        case 3:
            printf("Inventaire\n");
            break;
        case 4:
            printf("Fuire\n");
            break;
        default:
            printf("Somehow you fucked up...\n");//A CHANGER
            break;
    }
}

//fonction pour initaliser
void initEnt(Entity **pEntity) {
    if (!(*pEntity = (Entity *) malloc(sizeof(Entity)))) { exit(-1); }
    (*pEntity)->nom = 0;
    (*pEntity)->des = 0;
    (*pEntity)->pv = 1;
    (*pEntity)->pvMax = 1;
    (*pEntity)->xp = 0;
    (*pEntity)->level = 0;
    (*pEntity)->money = 0;
    (*pEntity)->atk = 0;
    (*pEntity)->def = 0;
    (*pEntity)->pos_x=0;
    (*pEntity)->pos_y=0;
    (*pEntity)->speed_x=0;
    (*pEntity)->speed_y=0;
    (*pEntity)->pos = 0;
    (*pEntity)->funcInter=menuInter;

    creationInvent(&(*pEntity)->inventaire);
    (*pEntity)->suivant = NULL;
    //printf("InitEntity\n");
}
//fonction pour ajouter au debut
//fonction pour ajouter a la fin
//fonction pour afficher (penser a faire une version courte)
void affIt(Entity *entity,int i,int full){
    printf("<<<STATS\n");
    if(i>=0){
        if (full==1)printf("\tentity->nom = ");
        printf("\t\"%s\"\n",entity->nom);
        if(i>=1){
            if (full==1)printf("\tentity->description = ");
            printf("\tTYPE %s\n",entity->des);
            if (full==1)printf("\tentity->pv = ");
            printf("\t%d PV\n",entity->pv);
            if (full==1)printf("\tentity->level = ");
            printf("\tLVL %d\n",entity->level);
            if (full==1)printf("\tentity->money = ");
            printf("\t%d OR\n",entity->money);
            if (full==1)printf("\tentity->xp = ");
            printf("\t%d XP\n",entity->xp);
            if(i>=2){
                if (full==1)printf("\tentity->pvMax = ");
                printf("\t%d PV MAX\n",entity->pvMax);
                if (full==1)printf("\tentity->atk = ");
                printf("\t%d ATQ\n",entity->atk);
                if (full==1)printf("\tentity->def = ");
                printf("\t%d DEF\n",entity->def);
            }
        }
    }
    printf("STATS>>>\n");
}
//fonction pour supprimer au debut
//fonction pour supprimer a la fin
//fonction pour retrouver
//fonction pour trier alphabetiquement (si vous etes chaud)
//FONCTION POUR MODIFIER-----------------------------------------------------//
/// Fonction ModName
/// \param pEntity
/// \param ptr
void modItName(Entity **pEntity,char *ptr){
    (*pEntity)->nom = ptr;
}
/// Fonction Mod Description
/// \param pEntity
/// \param ptr
void modItDes(Entity **pEntity,char *ptr){
    (*pEntity)->des = ptr;
}
/// Fonction Mod Points de vie
/// \param pEntity
/// \param ptr
void modItPv(Entity **pEntity,int ptr){
    (*pEntity)->pv = ptr;
}
/// Fonction Mod Points de max
/// \param pEntity
/// \param ptr
void modItPvMax(Entity **pEntity,int ptr){
    (*pEntity)->pvMax = ptr;
}
/// Fonction Mod Points d'experience
/// \param pEntity
/// \param ptr
void modItXp(Entity **pEntity,int ptr){
    (*pEntity)->xp = ptr;
}
/// Fonction Mod Niveau
/// \param pEntity
/// \param ptr
void modItLvl(Entity **pEntity,int ptr){
    (*pEntity)->level = ptr;
}
/// Fonction Mod Argent
/// \param pEntity
/// \param ptr
void modItMoney(Entity **pEntity,int ptr){
    (*pEntity)->money = ptr;
}
/// Fonction Mod Dégats
/// \param pEntity
/// \param ptr
void modItAtk(Entity **pEntity,int ptr){
    (*pEntity)->atk = ptr;
}
// Fonction Mod Défense
/// \param pEntity
/// \param ptr
void modItDef(Entity **pEntity,int ptr){
    (*pEntity)->def = ptr;
}
// Fonction Mod Pos
/// \param pEntity
/// \param ptrx, ptry
void modItPos(Entity **pEntity,int ptrx,int ptry){
    (*pEntity)->pos_x = ptrx;
    (*pEntity)->pos_y = ptry;
}
// Fonction Mod Speed
/// \param pEntity
/// \param ptrx, ptry
void modItSpeed(Entity **pEntity,int ptrx,int ptry){
    (*pEntity)->speed_x = ptrx;
    (*pEntity)->speed_y = ptry;
}

/// Fonction qui attribue un item a une entité
/// \param pEntity
/// \param pItem
void giveItem(Entity **pEntity,Item *pItem){
    ajoutFinInventaire((*pEntity)->inventaire,pItem);
}

/// Fonction qui redistribue un item et autres a une entité après combat
/// \param pEntity
/// \param pItem
void loot(Entity **from,Entity **to){
    if((*from)->inventaire->head){
        ajoutFinInventaire((*to)->inventaire,(*from)->inventaire->head);
    }
    printf("\"%s\" GAGNE %d XP %d OR\n",(*to)->nom,(*from)->xp,(*from)->money);
    modItXp(to,(*to)->xp+(*from)->xp);
    modItMoney(to,(*to)->money+(*from)->money);
    affIt((*to),1,0);
}

void lvlUp(Entity **to){
    printf("<<<\"%s\" MONTE DE LEVEL>>>\n",(*to)->nom);
    modItLvl(to,+1);
    modItPvMax(to,(*to)->pvMax+((*to)->level)*2);
    modItPv(to,(*to)->pvMax);
    modItXp(to,0);
    modItLvl(to, (*to)->level+1);
    modItMoney(to,(*to)->money+((*to)->level)*2);
    modItAtk(to,(*to)->atk+((*to)->level)*2);
    modItDef(to,(*to)->def+((*to)->level));
    printf("<<<\"%s\" RECOIS +1 POTION DE SOIN>>>\n",(*to)->nom);
    giveItem(to,InitSoin());
    affIt((*to),2,0);
}

void lvlDown(Entity **to){
    printf("<<<\"%s\" BAISSE DE LEVEL>>>\n",(*to)->nom);
    modItLvl(to,-1);
}
//--------------------------------------------------------------------------//
///Fonction qui appelle un pointeur de fonction pour utiliser l'item
/// \param pItem//A REVOIR
void choixInter(Entity **pEntity){
    int i;
    printf("Choix...[1:4]\n");
    scanf("%d",&i);
    (*pEntity)->funcInter(i);
}
//EXEMPLE DE POINTEUR SUR FONCTION

//FONCTION
//void papri(int i){
//    printf("chiffre %d",i);
//}
//POINTEUR SUR FONCTION
//typedef void (*func)(int i);
//
//INITIALISATION DE L'OBJET SUR POINTEUR
//func option1 = papri;
//
//APPEL DE POINTEUR SUR FONCTOION
//(*option1)(5);
#endif //BASH_ADVENTURE_ENTITY_H
