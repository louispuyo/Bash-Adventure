#include <stdio.h>
#include <string.h>


#define BLACK    "\033[1;30m"
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define YELLOW   "\033[1;33m"
#define BLUE     "\033[1;34m"
#define PURPLE   "\033[1;35m"
#define CYAN     "\033[1;36m"
#define GREY     "\033[1;37m"

#define DEFAULT_COLOR "\033[0;m"

int main(){
  char map[25][25], n_map[30]="Prairie verdoyante...";
  char c[20]="Joueur";
  int hp=20, dp=30, po=40;
  int lvl=50;
  int  k;
  int i, j;
  k=0;

  printf("\n");
  printf("\033[1;35m%s \n",n_map);
  // initialisation du tableau
  for(i=0; i<25; i++){
    for(j=0; j<25; j++){

      if( i == 0,  i == 24 ){
        map[i][j]='=';
      }
      else if( j == 0,  j == 24 ){
        map[i][j]='|';
      }
      else{
        map[i][j]='|';
      }

      map[5][5]='H';

    }
  }

  // Affichage du tableau
  for(i=0; i<25; i++){
    for(j=0; j<25; j++){

      if(map[i][j]=='=' || map[i][j]=='|'){
        printf("\033[1;35m%c",map[i][j]);
      }

      if(map[i][j]=='|'){
        printf("\033[0;32m%c",map[i][j]);
      }

      if(map[i][j]=='H'){
        printf("\033[1;33m%c",map[i][j]);
      }

      k++;
      if(k%30 == 0){
        printf("\n");
      }
    }
  }

  printf("\n \033[1;33mNom : %s;\n HP : %d; \033[1;37m\t\t[↑]:z\n \033[1;33mDP : %d; \033[1;37m\t[←]:q\t[↓]:s\t[→]:d  \n \033[1;33mPO : %d;\n", c, hp, dp, po);

  printf("\n");
  return 0;
}
