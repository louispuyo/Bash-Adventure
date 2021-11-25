#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGEUR 50


void ChargerNiveau()
// charger un niveau ou une map 
// depuis le repertoire res/map par exemple
{
    FILE *P_FICHIER; /* pointeur sur FILE */
  char NOM_FICHIER[60], element[10];
strcpy(NOM_FICHIER, "../../res/map/map-louis-test.txt");
//   printf("\n entrer le nom du fichier : ");
//   scanf("%s",NOM_FICHIER);
  int  C,NB_ENREG;
  NB_ENREG = 1000;
  P_FICHIER = fopen(NOM_FICHIER, "r");  /* read */
  C = 0;
  while (!feof(P_FICHIER))
     {
         
      fscanf(P_FICHIER, "%s", element);
      printf("%4s", element);
      if (C > LARGEUR)
      {
          C = 0;
          printf("\n");
      }
      C++;
     }
  fclose(P_FICHIER);

}


void Afficher(); // affiche la map 


//"../../res/map/map-louis-test.txt"

int main(int argc, char const *argv[])
{
    ChargerNiveau();
    
    return 0;
}
