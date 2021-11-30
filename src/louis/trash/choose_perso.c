#include <stdlib.h>
#include "../julio/player.h"
#include "../julio/entity.h"
// #include "../julio/monde.h"
#include "Sauvegarde.h"
#include "chargerPartie.h"

int main(int argc, char const *argv[])
{
 
   Entity *Player = malloc(sizeof(*Player));
//    *Player = selectionP();
    //menu_sauvegarde(Player->nom, Player->des, Player->pv, Player->pvMax, Player->xp, Player->level, Player->money, Player->atk, Player->atk, Player->def);
    printf("\n [i] DEBUG CHOOSE PLAYER \n");
    // charger_partie("sauv1.txt");

    //  *Player = txtToEntity();
    // printf("money %d \n", money);
    

    return 0;
}
