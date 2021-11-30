#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../julio/entity.h"

#ifndef _CHARGER_
#define _CHARGER_

#define DELIM        ","
#define BUFF_SIZE    128




typedef enum
{
   NOM,
   des,
   money,
   level,
   xp,

   NB_TYPE
}
infos_type;


static char * str_dup (const char * str)
{
   char * dup = NULL;


   if (str != NULL)
   {
      size_t size = strlen (str) + 1;
      dup = malloc (size);

      if (dup != NULL)
      {
         memcpy (dup, str, size);
      }
   }


   return dup;
}


Entity * loadFile (char * filename)
{
   Entity  *  infos = NULL;
   FILE           *  file  = NULL;
   char           *  token = NULL;
   char              buff [BUFF_SIZE];


   file = fopen (filename, "r");

   if (file != NULL)
   {
      if ((fgets (buff, BUFF_SIZE, file)) != NULL)
      {
         char *   p = buff;
         int      i = 0;


         infos = malloc (sizeof (* infos));

         if (infos != NULL)
         {
            while ((token = strtok (p, DELIM)) != NULL)
            {
               if (i == 0)
                  p = NULL;

               switch (i)
               {
                  case NOM:
                     infos->nom = str_dup (token);
                     break;

                  case des:
                     infos->des = str_dup (token);
                     break;

                  case money:
                    infos->money = 1; /*str_dup (token);*/
                     break;

                  case level:
                     infos->level = 1; /*str_dup (token);*/
                     break;

                  case xp:
                  {
                     int xp = strtol (token, NULL, 10);
                     infos->xp = xp;
                  }
                  break;

                  default:
                     break;
               }

               i++;
            }
         }
      }

      fclose (file);
   }


   return infos;
}


// static void free_Stats (Entity ** p)
// {
//    if (p != NULL && *p != NULL)
//    {
//       free ((*p)->nom);
//       free ((*p)->des);
//       free ((*p)->money);
//       free ((*p)->level);

//       free (*p);
//       *p = NULL;
//    }
// }



Entity txtToEntity (char *filename)
{
   Entity * infos = loadFile (filename);
   Entity* Tmp;
   if (infos != NULL)
   {
      printf (
         "nom:%s des: %s\nmoney : %s\nlevel : %d \n xp:%s\n\n",
         infos->nom, infos->des, infos->money, infos->xp, infos->level
      );

   }
 
   

      // free_Stats (& infos);

   return *infos;
}

#endif
