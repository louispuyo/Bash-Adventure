#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



int main(int argc, char *argv[])
{
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
  return 0;          // Le programme renvoie le nombre 0 puis s'arrête
}
