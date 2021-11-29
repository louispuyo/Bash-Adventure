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
#include "monde.h"
//INITIALISATION-------------------------------------------------------------//
void initialisation(){
    Entity *e,*e2;
    Monde *monde;
    creationMonde(&monde);
    initEnt(&e);
    *e=selectionP();
    initLizard(&e2);
    ajoutFinMonde(monde,e);
    ajoutFinMonde(monde,e2);
    supprimeEntMonde(monde,&e2);
    afficheMonde(monde);
    system("PAUSE");


//    Inventaire *inventaire;
//    creationInvent(&inventaire);
//    ajoutFinInventaire(inventaire,InitSword());
//    char *c = (char*) malloc(sizeof(char ));
//    scanf("%s",c);
//    strtok((char *) c, "\n");
//    afficheItem(chercherItem(inventaire,c),1,1);

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
void plat(){
        int plateau[50][100]; // le tableau 2D représentant le plateau de jeu
        int hauteur, largeur; // taille utile
        int blanc, noir;
        int ligne, colonne; // indices pour parcourir le tableau


        char case_blanche;

        case_blanche = 219; // Code ASCII d'une case blanche

        hauteur = 50;
        largeur = 100;

        blanc = 1;
        noir = 0;

        printf ("_______________________________________________________________________________\n\n");
        printf ("                              BashLife\n");
        printf ("_______________________________________________________________________________\n\n");


        for (ligne = 0 ; ligne<hauteur-1 ; ligne++)
        {
            for (colonne = 0 ; colonne<largeur-1 ; colonne++)
            {
                plateau[ligne][colonne]=(ligne+colonne) %2; // cela alterne des 0 et des 1
            }
        }

        for (ligne = 0 ; ligne<hauteur-1 ; ligne++)
        {
            for (colonne = 0 ; colonne<largeur-1 ; colonne++)
            {
                if (plateau[ligne][colonne]==0)
                {
                    printf("%c", case_blanche);
                    //printf(" "); // espace pour les cases noires
                }
                else
                {
                    printf("%c", case_blanche);
                }
            }

            printf("\n");
        }

        system("PAUSE");   // Le programme se met en pause
}

//---------------------------------------------------------------------------//
int main() {
    printf("Hello, World!\n");
    initialisation();
    //plat();
    return 0;
}

