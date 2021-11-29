//
// Created by Julio on 24/11/2021.
//

#ifndef BASH_ADVENTURE_INVENTAIRE_H
#define BASH_ADVENTURE_INVENTAIRE_H
//INCLUDE----------------------------------------------------------------//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
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
void creationInvent(Inventaire **ppl){
    if(!(*ppl=(Inventaire *)malloc(sizeof(Inventaire)))){exit(-1);}
    (*ppl)->head = NULL;
    (*ppl)->size = 0;
    //printf("Création de l'inventaire\n");
}

//fonction pour ajouter au debut
void ajoutDebutInventaire(Inventaire *inventaire, Item *item){
    Item *pc;
    initItem(&pc);
    pc->suivant = (inventaire)->head;
    inventaire ->head = item;
}

//fonction pour ajouter a la fin
void ajoutFinInventaire(Inventaire *inventaire, Item *item){
    if(inventaire->head) {
        Item *pc2 = inventaire->head;
        while(pc2->suivant) pc2 = pc2->suivant;
        pc2->suivant = item;
    }
    else{ // sinon c'est pareil qu'insérer en tete
        ajoutDebutInventaire(inventaire,item);
    }
    inventaire->size++;
    item->pos = inventaire->size;
}

/// Ajoute un item initialisé a null dans une liste
/// \param inventaire
void ajoutItemnull(Inventaire **pInventaire){
    Item *item;
    initItem(&item);
    //afficheItem(item);
    if ((*pInventaire)!=NULL && (item)!=NULL){item->suivant=NULL;}
    ajoutFinInventaire(*pInventaire,item);
}

//fonction pour afficher
/// Fonction pour afficher l'inventaire
/// \param inventaire
void afficheInvent(Inventaire *inventaire){
    printf("<<<SAC %d ITEMS\n",inventaire->size);
    if(inventaire->head){
        Item *pc = inventaire->head;
        while(pc){            // ou : while(pc != NULL){
            afficheItem(pc,1,0);
            //printf(" ");        // il faudrait éviter d'afficher le dernier
            // espace
            pc = pc->suivant;
        }
        //printf("\n");
    }else{ printf("TES POCHES SONT VIDES UTILISE TES MAINS\n");}
    printf("SAC>>>\n");
}
//fonction pour supprimer au debut

//fonction pour supprimer a la fin
//fonction pour retrouver

//fonction pour trier alphabetiquement (si vous etes chaud)

/// fonction pour retrouver l'Item
/// \param inventaire
/// \param c
/// \return
Item* chercherItem(Inventaire *inventaire,const char *c){
    int trouve = 0;
    Item *pc = inventaire->head;
    while ((!trouve)&&pc){
        if(pc->nom == c){
            trouve = 1;
        } else{
            pc = pc->suivant;
        }
    }
    if(trouve==0){ //printf("\tItem non trouvé\n");
        initItem(&pc);} else{ //printf("Trouvé\n");
         }
    return pc;
}

/// fonction pour retrouver l'Item
/// \param inventaire
/// \param c
/// \return
Item* chercherItemInt(Inventaire *inventaire,int i){
    int trouve = 0;
    Item *pc = inventaire->head;
    while ((!trouve)&&pc){
        if(pc->pos == i){
            trouve = 1;
        } else{
            pc = pc->suivant;
        }
    }
    if(trouve==0){ //printf("\tItem non trouvé\n");
        initItem(&pc);} else{ //printf("Trouvé\n");
    }
    return pc;
}

//fonction pour détruire un item
void destructionItem(Item **ppc){
    if(*ppc){       // protection contre les destructions de pointeur null
        free(*ppc);
        *ppc = NULL;  // important pour éviter une réutilisation du pointeur après la libération
    }               // de la mémoire (c'est pour cela qu'on passe la pointeur par référence)
}
//fonction pour detruire un Inventaire
void destructionListe(Inventaire **ppl){
    if(*ppl){       // protection contre les destructions de pointeur null
        // il faut commencer par détruire les éléments de la liste
        while((*ppl)->head){
            Item *pc = (*ppl)->head->suivant;
            // destructionCellule(&(*ppl)->tete); // joli mais non optimal
            free((*ppl)->head); // est préférable (une affectation inutile en
            // moins)
            (*ppl)->head = pc;
        }

        free(*ppl);
        *ppl = NULL;
    }
}

//--------------------------------------------------------------------------//
#endif //BASH_ADVENTURE_INVENTAIRE_H
