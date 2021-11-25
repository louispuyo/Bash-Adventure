// Louis 25/11 //
// description : Sauvegarder et Charger une Partie //
// Note: changer les chemins de entity.h apres le merge des branches //

#include <stdio.h>
#include <stdlib.h>
#include "../julio/entity.h"
#include "utils.h"


#define _PATH_SAUV_ "../../res/sauvegardes/" // chemin sauvegarde
#define _FILENAME_ "sauvegarde.txt"
#define _TAILLE_MAX_ 1000
#define _SEPARATOR_ "|"


/// \param nom
/// \param des description
/// \param pv
/// \param pvMax
/// \param xp
/// \param level
/// \param money
/// \param action
/// \param atk
/// \param def
/// \param suivant -> type Entity -> liste chainee

FILE *fopen(const char *nomDuFichier, const char *modeOuverture);


void sauver_partie(char *nom,
                   char *des,
                   int pv,
                   int pvMax,
                   int xp,
                   int level,
                   int money,
                   int action,
                   int atk,
                   int def,
                //    Entity suivant,
                   char *filename)

{
    char *chemin_fichier = concat(_PATH_SAUV_, filename); // from utils.h
    FILE *file = NULL;
   
    file = fopen(chemin_fichier, "w+"); 

    if(file != NULL){


    fprintf(file, "nom: %s %s", nom, _SEPARATOR_);
    fprintf(file, "des: %s %s", des, _SEPARATOR_);
    fprintf(file, "pv: %d %s", pv, _SEPARATOR_);
    fprintf(file, "pvMax: %d %s", pvMax, _SEPARATOR_);
    fprintf(file, "xp: %d %s", xp, _SEPARATOR_);
    fprintf(file, "level: %d %s", level, _SEPARATOR_);
    fprintf(file, "money: %d %s", money, _SEPARATOR_);
    fprintf(file, "action: %d %s", action, _SEPARATOR_);
    fprintf(file, "atk: %d %s", atk, _SEPARATOR_);
    fprintf(file, "def: %d %s", def, _SEPARATOR_);
    // fprintf(file, "suivant: %s %s", suivant, _SEPARATOR_);
    fprintf(file, "nom: %s %s", nom, _SEPARATOR_);

    fclose(file);
    printf("[i] Vous Avez sauvez la Partie ! \n");
    }
    else{
        printf("[!] ERREUR LORS DE LA SAUVEGARDE DU FICHIER ! \n");

        exit(EXIT_FAILURE);
    }
}

char* charger_partie(char *filename)
{
    char *chemin_fichier = concat(_PATH_SAUV_, filename); // from utils.h
    FILE *file = NULL;
    char *Conteneur = malloc_p(_TAILLE_MAX_ * sizeof(char)); // from utils.h
   
    file = fopen(chemin_fichier, "r"); 

    if(file != NULL)
    {
        Conteneur = fgets(Conteneur, _TAILLE_MAX_, file);

        printf("%s", Conteneur); // On affiche pour debug 
 
        fclose(file);
    }
    else 
    {   
        printf("[!] LE FICHIER N'EXISTE PAS OU ERREUR LORS DE SON OUVERTURE ! \n");
        exit(EXIT_FAILURE);
        }
    return Conteneur;
}

///  MENU ///

void menu_sauvegarde(char *nom,
                     char *des,
                     int pv,
                     int pvMax,
                     int xp,
                     int level,
                     int money,
                     int action,
                     int atk,
                     int def)
                    //  Entity suivant

{

    FILE *fichier = NULL;
    int choix;
    // faire une menu -> lier a l autre menu principale

    printf("Voulez Vous Sauvegarder (1) ou Charger (2) une partie existante : \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        sauver_partie(nom,
                      des,
                      pv,
                      pvMax,
                      xp,
                      level,
                      money,
                      action,
                      atk,
                      def,
                    //   suivant,
                      _FILENAME_
                      );
        break;
    case 2:
        charger_partie(_FILENAME_); 

        break;

    default:
        break;
    }
}



int main(int argc, char const *argv[])
{
    menu_sauvegarde("louis", "perso de test", 100, 100, 0, 1, 100, 0, 50, 200); // exemple
    return 0;
}
