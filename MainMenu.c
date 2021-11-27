int choix=-1, test=0;

    system ("clear");            /*efface l'ecran*/
    printf("Bienvenue sur Bash-Adventure\n");
    printf("-1- Nouvelle partie\n");
    printf("-2- Charger\n");
    printf("-0- Quitter\n");
    printf("Choix?");
    scanf("%d",&choix);

    switch (choix)
    {
        case 1 :initialisation();
            c=0;
            nouveaujeu();
            break;
        case 2 :chargement();
            break;
        case 0 :printf("Au revoir\n");
            break;
        default :printf("Erreur de saisie\n");
             break;
    }