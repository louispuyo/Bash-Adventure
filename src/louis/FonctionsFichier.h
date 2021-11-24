#ifndef FonctionsFichier
#define FonctionsFichier


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structures // Remplacer les structures par Celles du jeu et adapter les fonctions 
typedef struct Contact contact; 

struct Contact
{
    char numero[13];
    char nom[20];
    char *adresse;
    contact *suivant;
};

typedef struct Liste Liste;

struct Liste
{
    int taille;
    contact *queue;
    contact *tete;
    contact *suivant;
};

void *malloc_p(size_t s)
{
    void *p;
    if (!(p = malloc(s)))
    {
        exit(EXIT_FAILURE);
    }

    return p;
}

int EcrireDansFichierJSON(Liste *ll)
{


FILE *P_FICHIER; /* pointeur sur FILE */
  char NOM_FICHIER[30], NOM_PERS[30];
  int  C,NB_ENREG;

  /* Première partie : 
     Créer et remplir le fichier */
//   printf("Entrez le nom du fichier à créer : ");
//   scanf("%s", NOM_FICHIER);
 strcpy(NOM_FICHIER,"octobre2021");
  P_FICHIER = fopen(strcat(NOM_FICHIER, ".json"), "w");  /* write */
  NB_ENREG = ll->taille;
  contact *t = ll->tete; 
  C = 0;
  fprintf(P_FICHIER, "{\"CONTACT\":[ \n");
  while (C<NB_ENREG)
     { 
      
    

      fprintf(P_FICHIER, "{\"nom\" : \"%s\" , \n", t->nom);
      fprintf(P_FICHIER, "\t \"numero\":\"%s\"}", t->numero);
      
      if (C<NB_ENREG-1){
         fprintf(P_FICHIER, ",\n");

      }
      else{
          fprintf(P_FICHIER, "\n");
      }
      
      t = t->suivant;
    
      C++;
     }
      fprintf(P_FICHIER, "]}");
  fclose(P_FICHIER);


  return 0;
}




void ecrireDansFichier(Liste *ll)
{
    contact *inc = ll->tete;
    FILE *Handle = fopen("repertoire.txt", "wb");

    // AfficheListe the last cell
    

  

    if (Handle != NULL)
    {
        char nom[20];
        char numero[10];
        char virgule[2];
        strcpy(nom, inc->nom);
        strcpy(numero, inc->numero);
        strcpy(virgule, ",");
        
        fwrite(numero, 1, strlen(numero), Handle);
        fwrite(virgule, 1,  strlen(virgule), Handle);
        fwrite(nom, 1, strlen(nom), Handle);
        fclose(Handle);
    }
}

void chargerRep()
{

FILE *P_FICHIER; /* pointeur sur FILE */
  char NOM_FICHIER[30], NOM_PERS[30];
  printf("\n entrer le nom du fichier : ");
  scanf("%s",NOM_FICHIER);
  int  C,NB_ENREG;
  P_FICHIER = fopen(NOM_FICHIER, "r");  /* read */
  C = 0;
  while (!feof(P_FICHIER))
     {
         
      fscanf(P_FICHIER, "%s\n", NOM_PERS);
      printf("NOM : %s\n", NOM_PERS);
      C++;
     }
  fclose(P_FICHIER);
}







void insVide(contact *contact)
{
    
    printf("\n*** Creation d'un nouveau contact ***\n");
    printf("\n Saisir un nom : ");
    scanf("%s", contact->nom);
    printf("\nSaisir un numero : ");
    scanf("%s", contact->numero);

}


// creation Du Fichier
FILE *fopen(const char *nomDuFichier, const char *modeOuverture);
// procedure sur le fichier
// ferme le fichier
int fclose(FILE *pointeurSurFichier);

// lit le fichier
int fgetc(FILE *pointeurDeFichier);


#endif
