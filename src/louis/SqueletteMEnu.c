#include <stdio.h>
#include <stdlib.h>
#include "../julio/entity.h"
#include "chargerPartie.h"
// #include <conio.h>

int main(void)
{
   int fin;
  char filename[40];
  Entity *Player = malloc(sizeof(*Player));
   fin = 0;
   while (!fin)
   {
      int c;

      /* affichage menu */
      printf("1.Nouvelle Partie 1\n"
             "2.Charger Partie 2\n"
             "3.Quitter\n");

      c = getchar();

      /* suppression des caracteres dans stdin */
      if (c != '\n' && c != EOF)
      {
         int d;
         while ((d = getchar()) != '\n' && d != EOF)
            ;
      }

      switch (c)
      {
      case '1':
         printf("Nouvelle Partie\n");
         system("./game");

      case '2':
         printf("Charger Partie\n");
         
         printf("\n entrer le fichier : ");
         // fgets(filename, 40, stdin);
         scanf("%s", &filename);
         *Player = txtToEntity(filename);
         // printf("%s", filename);
         
         break;

      case '3':
         printf("Quitter\n");
         exit(EXIT_SUCCESS);
         break;

      default:
         printf("Choix errone\n");
      }
   }

   return 0;
}
