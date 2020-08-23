#include <stdio.h> 
#include <stdlib.h> 

struct 
{
    int jour;
    int mois;
    int annee;
}Date;

struct 
{
    Date datex;
    int nExamen;
    string matiere;
    double coeff;
}Examen;

void afficheExamen(struct Examen Ex)
{
    printf("le numero d'examen est %d ",Ex.datex);
    printf("la matiere est %s ",Ex.matiere);
    printf("le coefficient est %f ",Ex.coeff);
    printf("la date de l'examen est %d/%d/%d ",Ex.datex.jour,Ex.datex.mois,Ex.datex.annee);
}

//dynamic array memory allocation
struct Examen *Tab;
Tab=(struct Examen*)malloc(n*sizeof(struct Examen));

void afficheToutExamen (struct Examen*Tab, int n)
{
    Tab=(struct Examen*)malloc(n*sizeof(struct Examen)); //better to put here 
    int i;
    for (i=0;i<n;i++)
    {
        afficheExamen(Tab[i]);
    }
}



