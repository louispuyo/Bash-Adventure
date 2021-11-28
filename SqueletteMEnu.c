#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
   int fin;

   fin = 0;
   while(!fin)
   {
      int c;

      /* affichage menu */
      printf("1.Nouvelle Partie 1\n"
             "2.Charger Partie 2\n"
             "3.Quitter\n");

      c = getchar();

      /* suppression des caracteres dans stdin */
      if(c != '\n' && c != EOF)
      {
         int d;
         while((d = getchar()) != '\n' && d != EOF);
      }

      switch(c)
      {
         case '1':
            printf("Nouvelle Partie\n");
            break;

         case '2':
            printf("Charger Partie\n");
            break;

         case '3':
            printf("Quitter\n");
            break;

         default:
            printf("Choix errone\n");
      }
   }

   return 0;
}
