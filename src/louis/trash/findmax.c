// #ifdef

// Action find_max(Action *list_action)
// {
//   Action *A = malloc_p((_MEMORY_SIZE_*sizeof(Action))); 
//  int N;     /* dimension      */
//  int I;     /* indice courant */
//  int MIN;   /* position du minimum */
//  int MAX;   /* position du maximum */
//  /* Saisie des données */
//  printf("Dimension du tableau (max.50) : ");
//  scanf("%d", &N );
//  for (I=0; I<N; I++)
//     {
//      printf("Elément %d : ", I);
//      A[I] = list_action[I];
//     }
//  /* Affichage du tableau */
//  printf("Tableau donné :\n");
//  for (I=0; I<N; I++)
//      printf("%d ", A[I].score);
//  printf("\n");
//  /* Recherche du maximum et du minimum */
//  MIN=0;
//  MAX=0;
//  for (I=0; I<N; I++)
//      {
//       if(A[I].score>A[MAX].score) MAX=I;
//       if(A[I].score<A[MIN].score) MIN=I;
//      }
//   /* Edition du résultat */
//  printf("Position du minimum : %d\n", MIN);
//  printf("Position du maximum : %d\n", MAX);
//  printf("Valeur   du minimum : %d\n", A[MIN]);
//  printf("Valeur   du maximum : %d\n", A[MAX]);
//  return A[MAX];
// }

