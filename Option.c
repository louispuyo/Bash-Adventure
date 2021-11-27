void Option()
{
int choix=-1;
char vide[2], retour[2];

    system ("clear");        /*efface l'ecran*/
    printf("Options\n");
    printf("-1- Retour au menu principal\n");
    printf("-2- Enregistrement de la partie\n");
    printf("-0- Retour à la partie\n");

    printf("Choix?");
    scanf("%d",&choix);
    switch (choix)
    {
        case 1 :main();
            break;
        case 2 :sauvegarde();
            break;
        case 0 :c--;
            nouveaujeu();
            break;
        default :printf("Erreur de saisie\n");
             printf("Tapez sur n'importe qu'elle touche !\n");
             scanf("%s",vide);
             scanf("%s",retour);
             c--;
             nouveaujeu();
             break;
    }
}