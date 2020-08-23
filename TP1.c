#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct etudiant
{
    char nom[20];
    char prenom[20];
    float note;
}etudiant;

//enter a list of students then print a list of students 
//with a mark equal to or higher than 10

int main()
{
    int n,i;
    etudiant *T;
    printf("donnez le nombre des etudiants \n");
    scanf("%d",n);
    T=(etudiant*)malloc(n*sizeof(etudiant));
    printf("entrez les informations des etudiants \n");
    for(i =0 ;i < n ; i++)
    {
        printf("donnez les informations du etudiants n %d \n",i);
        scanf("%s",(T+i)->nom);
        scanf("%s",(T+i)->prenom);
        scanf("%d",(T+i)->note);
    }
    for(i = 0 ; i < n ; i++)
    {
        if((T+i)->note >= 10)
        {
            printf("nom : %s \n",(T+i)->nom);
            printf("prenom : %s \n",(T+i)->prenom);
            printf("note : %d \n",(T+i)->note);
        }
    }
    for (i = 0 ; i < n ; i++)
    {
        if((T+i)->note < 10)
        {
            (T+i)->note += 1;
        }
        if((T+i)->note >= 10 && (T+i)->note <= 15)
        {
            (T+i)->note += 0.5;
        }
    }
    printf("informations apres modification :\n");
     for(i = 0 ; i < n ; i++)
    {    
        printf("nom : %s \n",(T+i)->nom);
        printf("prenom : %s \n",(T+i)->prenom);
        printf("note : %d \n",(T+i)->note);
    }
}
//