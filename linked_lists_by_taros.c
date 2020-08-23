#include <stdio.h>
#include <stdlib.h>

typedef struct liste
{
  int nombre;
  struct liste *suivant;
} liste;

//creates head of list and keeps creating nodes  
void allocation_dernier(liste **ptr)
//double pointer to use it for both looping and using as argument
{
	if (*ptr == NULL)
	{
		*ptr = (liste *)malloc(sizeof(liste));
		(*ptr)->suivant = NULL;
	}
	else
	{
		while((*ptr)->suivant != NULL)
			(*ptr) = (*ptr)->suivant;
		(*ptr)->suivant = (liste *)malloc(sizeof(liste));
		(*ptr) = (*ptr)->suivant;
		(*ptr)->suivant = NULL;
	}
}
//passes head as argument in case pos = 1
void	allocation_position(liste **tete, int pos)
{
	liste *ptr;//the element we use to move inside the program
	liste *derriere;//the node before ptr 

	if (pos <= 1)
	{
		derriere = (liste *)malloc(sizeof(liste));
		derriere->suivant = *tete;
		*tete = derriere;
	}
	else
	{
		ptr = *tete;//we should always start from the head as the looping method induces 
		for (int i = 1; i < pos; i++)
		{
			if (ptr == NULL)
				break;
			derriere = ptr;
			ptr = ptr->suivant;
		}
		derriere->suivant = (liste *)malloc(sizeof(liste));
		derriere = derriere->suivant;
		derriere->suivant = ptr;
	}
}

void	afficher_liste(liste *tete)
{
	while (tete != NULL)
	{
		printf("%d ", tete->nombre);
		tete = tete->suivant;
	}
	printf("\n");
}

void	trier(liste *tete)
{
	int		ech;
	int		temp;
	liste	*ptr;
	liste	*derriere;

	derriere = NULL;
	do
	{
		ech = 0;
		ptr = tete;
		while (ptr->suivant != derriere)
		{
			if (ptr->nombre > ptr->suivant->nombre)
			{
				temp = ptr->nombre;
				ptr->nombre = ptr->suivant->nombre;
				ptr->suivant->nombre = temp;
				ech = 1;
			}
			ptr = ptr->suivant;
		}
		derriere = ptr;
	} while (ech);

}

void	separer(liste *tete)
{
	liste	*ptr;
	liste	*pair = NULL;
	liste	*pair_tete;
	liste	*impair = NULL;
	liste	*impair_tete;
	int		i = 0, j = 0;
	ptr = tete;
	while(ptr != NULL)
	{
		if ((ptr->nombre % 2) == 0)
		{
			allocation_dernier(&pair);
			if (i == 0)
				pair_tete = pair;
			pair->nombre = ptr->nombre;
			i++;
		}
		else if ((ptr->nombre % 2) == 1)
		{
			allocation_dernier(&impair);
			if (j == 0)
				impair_tete = impair;
			impair->nombre = ptr->nombre;
			j++;
		}
		ptr = ptr->suivant;
	}
	printf("la liste des elements  pair: \n ");
	afficher_liste(pair_tete);
	printf("la liste des elements impairs \n: ");
	afficher_liste(impair_tete);
}
int main ()
{
	liste		*ptr = NULL;
	liste		*sv = NULL;
	liste		*tete = NULL;
	int			t;
	int			i;

	printf("entrez le nombre des elements: ");
	scanf("%d", &t);
	if (t == 0)
		return (-1);
	for (i = 0; i < t; i++)
	{
		allocation_dernier(&ptr);
		if (i == 0)
			tete = ptr;
		printf("entrez l'entier: ");
		scanf("%d", &(ptr->nombre));
	}
	afficher_liste(tete);
	printf("entrer position: ");
	scanf("%d", &t);
	allocation_position(&tete, t);
	ptr = tete;
	for (i = 1; i < t; i++)
	{
		if (ptr->suivant == NULL)
			break;
		ptr = ptr->suivant;
	}
	printf("entrez l'entier: ");
	scanf("%d", &(ptr->nombre));
	afficher_liste(tete);
	printf("apres tri: ");
	trier(tete);
	afficher_liste(tete);
	separer(tete);
  return 0;
}
