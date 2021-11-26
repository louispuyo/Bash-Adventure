//
// Created by Julio on 24/11/2021.
//

#ifndef BASH_ADVENTURE_INVENTAIRE_H
#define BASH_ADVENTURE_INVENTAIRE_H
//INCLUDE----------------------------------------------------------------//
#include "main.h"
#elif defined(BASH_ADVENTURE_INVENTAIRE_H)
    #include "item.h"
//--------------------------------------------------------------------------//

//CONSTANTES----------------------------------------------------------------//


//--------------------------------------------------------------------------//
typedef struct Liste {
    Item *head;//tete de la liste Inventaire
    int size;//taille de l'inventaire
}Inventaire;

//POUR INVENTAIRE-----------------------------------------------------------//
//<fonction qui affiche> simple pointeur "void func(*args){}"
//<fonction qui agit> double pointeur "void func(**args){}"
//<fonction qui sert d'option> pointeur de fonction "(*option)(*args)"
// "void func (*args){}"

//fonction pour initaliser avec un malloc
//fonction pour ajouter au debut
//fonction pour ajouter a la fin
//fonction pour afficher
//fonction pour supprimer au debut
//fonction pour supprimer a la fin
//fonction pour retrouver
//fonction pour trier alphabetiquement (si vous etes chaud)
//fonction pour modifier

//--------------------------------------------------------------------------//
#endif //BASH_ADVENTURE_INVENTAIRE_H
