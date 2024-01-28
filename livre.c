#include <stdio.h>
#include <stdlib.h>
#include "livre.h"
#include <string.h>


    void saisirlivre (livre *l)
{
    int val1,val2;
    do
    {
        val1=0;
        val2=0;
        printf("donner la reference\n");
         //scanf("%s",(*l).reff);
        fflush(stdin);
        gets((*l).reff);
        for(int i=0; i<strlen((*l).reff); i++)
        {
            if(((*l).reff[i]>=48)&&((*l).reff[i]<=57))
                val1=1;
            if(((*l).reff[i]>='a'&&((*l).reff[i]<='z'))||(((*l).reff[i]>='A')&&((*l).reff[i]<='Z')))
                val2=1;
        }
        if ((val1==0) || (val2==0))
            {
            printf("la refrence de la livre doit contenir au moins un chiffre et une lettre \n");
        }

    }
    while((val1==0)||(val2==0));

    printf("donner le nom d'lauteur du livre:\n");
    scanf("%s",(*l).nom);
    printf("donner le prenom de l'auteur du livre :\n");
    scanf("%s",(*l).prenom);
    printf("donner le nombre d'exemplaire du livre:\n");
    scanf("%d",&(*l).nbe);
    printf("donner la jour d'ajout:\n");
    scanf("%d",&(*l).date.jour);
    printf("donner le mois d'ajout:\n");
    scanf("%d",&(*l).date.mois);
    printf("donner l'annee d'ajout:\n");
    scanf("%d",&(*l).date.annee);
}



int remplirbibliotheque(livre tab[])
{
    int i,n;

    printf("donner le nombre de livre :\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        saisirlivre(& tab[i]);
    }
    return n;
}
void afficherlivre(livre tab[],int n,char nom[],char prenom[])
{
    int i;
    for(i=0; i<n; i++)
    {
        if((strcmp(nom,tab[i].nom)==0)&&(strcmp(prenom,tab[i].prenom)==0))
        {
            printf(" la reference : %s\n",tab[i].reff);
            printf("  nom et prenom de l'auteur :  %s  %s\n",tab[i].nom,tab[i].prenom);
            //printf("  prenom de l'auteur : %s\n",tab[i].prenom);
            printf("  nombre d'exemplaire  : %d\n",tab[i].nbe);
            printf("  date d'ajout: %d / %d / %d  \n " ,tab[i].date.jour,tab[i].date.mois,tab[i].date.annee);
            printf("------------------------------------\n");

            //printf("%d / %d / %d  \n",tab[i].date.jour,tab[i].date.mois,tab[i].date.annee);

           /* printf("c'est le jour:%d\n",tab[i].date.jour);
            printf("c'est le mois:%d\n",tab[i].date.mois);
            printf("c'est le annee:%d\n",tab[i].date.annee);*/

            //break;
        }
        else printf("il n y'a pas un auteur qui a ce nom et ce prenom.\n");
    }

}
int chercherlivre(livre tab[],int n,char reff[])
{
    int i ;
    for(i=0; i<n; i++)
    {
        if(strcmp(tab[i].reff,reff)==0)
        {
            return i;
        }
    }
    return -1;
}
void calculdiff(date dateajout,date datecourante,int *jour)
{
    int a,j,m;
    a=datecourante.annee-dateajout.annee;
    m=datecourante.mois-dateajout.mois;
    j=datecourante.jour-dateajout.jour;
    (*jour)=365*a+30*m+j;
    printf("la difference egale = %d jour",(*jour));
}
int miseajour(livre tab[],int n)
{
    date d;
    int jour,i,j;
    printf("donner la date courante:\n");
    printf("donner la jour courante :\n");
    scanf("%d",&d.jour);
    printf("donner la mois courante :\n");
    scanf("%d",&d.mois);
    printf("donner la annee courante :\n");
    scanf("%d",&d.annee);
    for(i=0; i<n; i++)
    {
        jour=0;
        calculdiff(tab[i].date,d,&jour);
        if(jour>=365)
        {
            for(j=i; j<n; j++)
            {
                tab[j]=tab[j+1];
            }
            n--;
        }
    }
    return n;
}
void init(int vente[][3])
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            vente[i][j]=0;
        }
    }
}
void ventelivre(livre tab[],int vente[][3],int *n,char reff[],int jour,int semaine)
{
    int i,j;
    i=chercherlivre(tab,(*n),reff);
    if(i==-1)
        printf("ce livre n'existe pas\n");
    else
    {
        tab[i].nbe--;
        if(tab[i].nbe==0)
        {
            for(j=i; j<(*n); j++)
            {
                tab[j]=tab[j+1];
            }
            (*n)--;
        }
        vente[semaine-1][jour-1]++;
    }
}
void afficherstat(int vente[][3],int seuil)
{
    int s1,s2,s3,i;
    for(i=0; i<3; i++)
    {
        s1=vente[0][i];
        s2=vente[1][i];
        s3=vente[2][i];
    }
    if((s1>seuil)&&(s2>seuil)&&(s3>seuil))
    {
        printf("les jours qui sont superieur a ce seuil sont lundi , mardi , mercredi.\n");
    }
    else if((s1<seuil)&&(s2<seuil)&&(s3<seuil))
        printf("il ya pas un somme de jours qui est superieur a ce seuil.\n ");
    else if((s1>seuil)&&(s2<seuil)&&(s3>seuil))
        printf("les jours qui sont superieur a ce seuil sont lundi , mercredi.\n");
    else if((s1<seuil)&&(s2>seuil)&&(s3>seuil))
        printf("les jours qui sont superieur a ce seuil sont mardi , mercredi.\n");
    else if((s1>seuil)&&(s2>seuil)&&(s3<seuil))
        printf("les jours qui sont superieur a ce seuil sont lundi , mardi.\n");
    else if((s1<seuil)&&(s2<seuil)&&(s3>seuil))
        printf("le jour qui est  superieur a ce seuil est mercredi.\n");
    else if ((s1>seuil)&&(s2<seuil)&&(s3>seuil))
        printf("le jour qui est  superieur a ce seuil est lundi.\n");
    else if ((s1<seuil)&&(s2>seuil)&&(s3>seuil))
        printf("le jour qui est  superieur a ce seuil est mardi.\n");

}





