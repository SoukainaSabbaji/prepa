#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ville{
	char nom[20];
	int nbr;
};
typedef struct ville Ville;
int main()
{
	Ville t[100];
	Ville tmp;
	int i,j,n;
	printf("Donnez le nombre de villes:\t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Donnez le nom de la ville N %d:\t",i+1);
		scanf("%s",t[i].nom);
		printf("Donnez le nombre d'habitants de cette ville:\t");
		scanf("%d",&t[i].nbr);
	}
	for(i=0;i<n;i++)
		printf("-- Le nombre d'habitants de %s est : %d\n",t[i].nom,t[i].nbr);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(t[j].nbr>t[j+1].nbr)
			{
				strcpy(tmp.nom,t[j].nom);
				tmp.nbr = t[j].nbr;

				strcpy(t[j].nom,t[j+1].nom);
				t[j].nbr = t[j+1].nbr;

				strcpy(t[j+1].nom,tmp.nom);
				t[j+1].nbr = tmp.nbr;
			}
		}
	printf("Les villes dans l'ordre croissant du nombre d'habitants:\n");
	for(i=0;i<n;i++)
		printf("-- Le nombre d'habitants de %s est : %d\n",t[i].nom,t[i].nbr);
	return 0;
}
