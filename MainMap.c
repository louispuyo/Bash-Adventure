void tableau2()
{
    int a, b, c;
    c=0;
    printf("  a    b    c    d    e    f    g    h \n" );
for (a=0;a<8;a++)
{
    printf(" ___  ___  ___  ___  ___  ___  ___  ___ \n" );
        printf("|   ||   ||   ||   ||   ||   ||   ||   |\n" );
 for (b=0;b<8;b++)
 {
  c++;
            if ( c % 8 == 0)
  printf("| %c |%d",'b',c/8);
            else printf("| %c |",'b');
 }
        printf("\n|___||___||___||___||___||___||___||___|\n" );
}
printf("  a    b    c    d    e    f    g    h \n" );
}