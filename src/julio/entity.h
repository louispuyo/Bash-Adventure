//
// Created by Julio on 24/11/2021.
//

#ifndef BASH_ADVENTURE_ENTITY_H
#define BASH_ADVENTURE_ENTITY_H
//INCLUDE----------------------------------------------------------------//
#include "main.h"
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

    Entity *suivant;
};

//POUR ENTITY----------------------------------------------------------------//
//<fonction qui affiche> simple pointeur "void func(*args){}"
//<fonction qui agit> double pointeur "void func(**args){}"
//<fonction qui sert d'option> pointeur de fonction "(*option)(*args)"
// "void (*func)(*args){}"

//fonction pour initaliser
void initIt(Entity **pEntity) {
    if (!(*pEntity = (Entity *) malloc(sizeof(Entity)))) { exit(-1); }
    (*pEntity)->nom = 0;
    (*pEntity)->des = 0;
    (*pEntity)->pv = 1;
    (*pEntity)->pvMax = 1;
    (*pEntity)->xp = 0;
    (*pEntity)->level = 0;
    (*pEntity)->money = 0;
    //(*pEntity)->action = 0;
    (*pEntity)->atk = 0;
    (*pEntity)->def = 0;
    (*pEntity)->suivant = NULL;
    printf("InitEntity\n");
}
//fonction pour ajouter au debut
//fonction pour ajouter a la fin
//fonction pour afficher (penser a faire une version courte)
void affIt(Entity *entity){
    printf("entity->nom = %s\n",entity->nom);
    printf("entity->description = %s\n",entity->des);
    printf("entity->pv = %d\n",entity->pv);
    printf("entity->pvMax = %d\n",entity->pvMax);
    printf("entity->xp = %d\n",entity->xp);
    printf("entity->level = %d\n",entity->level);
    printf("entity->money = %d\n",entity->money);
    printf("entity->atk = %d\n",entity->atk);
    printf("entity->def = %d\n",entity->def);
    //printf("entity->vie = %d",entity->options);
    //printf("");
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
//--------------------------------------------------------------------------//

//fonction d'interaction



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
