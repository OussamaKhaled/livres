#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED
typedef struct
{
    int jour;
    int mois;
    int annee;
}date;
typedef struct
{
    char reff[30];
    char nom[30];
    char prenom[40];
    int nbe;
    date date;
}livre;

void saisirlivre(livre *l);
int remplirbibliotheque(livre tab[]);
void afficherlivre(livre tab[],int n,char nom[],char prenom[]);
int chercherlivre(livre tab[],int n,char reff[]);
void calculdiff(date dateajout,date datecourante,int *jour);
int miseajour(livre tab[],int n);
void init(int vente[][3]);
void ventelivre(livre tab[],int vente[][3],int *n,char reff[],int jour,int semaine);
void afficherstat(int vente[][3],int seuil);

#endif // LIVRE_H_INCLUDED
