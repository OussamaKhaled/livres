#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livre.h"
int main()
{   livre tl[30];
    int n=0,choix,j,s,seuil;
    char nom[30] , pren[30],reff[20];
    int vente[4][3];

    init(vente);
    do{
       do{
    printf("*********************************\n");
    printf("1-remplissage de la biblotheque.\n");
    printf("2-affichage de la liste des livres d'un auteur.\n");
    printf("3-mise a jour de la bibliotheque.\n");
    printf("4-vente d'un livre.\n");
    printf("5-affichage des statistique.\n");
    printf("0-quitter.\n");
    printf("*********************************\n");
    scanf("%d",&choix);
       }while(choix<0||choix>5);
       switch(choix)
       {
           case 1 :
                    n=remplirbibliotheque(tl);
               break;
           case 2 : printf("donner le nom de l'auteur:\n");
                     scanf("%s",nom);
                     printf("donner le prenom de l'auteur.\n");
                     scanf("%s",pren);
                     afficherlivre(tl,n,nom,pren);
               break;
           case 3 :n=miseajour(tl,n);
                    break;
           case 4 :printf("donner la reference du livre:\n");
                   fflush(stdin);
                   scanf("%s",reff);
                   printf("donner le jour:\n");
                   scanf("%d",&j);
                   printf("donner la semaine:\n");
                   scanf("%d",&s);
                   ventelivre(tl,vente,&n,reff,j,s);
               break;
           case 5 : printf("donner un seuil:\n");
                    scanf("%d",&seuil);
                    afficherstat(vente,seuil);
               break;
       }
}while(choix!=0);
    return 0;
}
