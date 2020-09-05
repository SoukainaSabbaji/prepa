#define d_max 7 //taille maximale pile
//iwannakms 
typedef struct
{ 
	int Tab[d_max];
	int sommet;
}pile;

pile initialisation()
{ 
	Pile p;
	p.sommet = -1;

	return p; 
}

int est_vide(pile p)
{
	if(p.sommet==-1)
		return 1;
	else 
		return 0;
}

pile empiler (int e, Pile p) 
{
	if(p.sommet >= d_max-1) 
	{
		printf("Erreur: pile pleine !\n");
		exit(-1);
	}
	(p.sommet)++;
	(p.tab)[p.sommet]=e;
	return p; 	
}

int depiler(Pile p) 
{ 
	int x;
	if(est_vide(p)==1) 
	{
		printf("Erreur: pile vide");
		exit(-1);
	}
	x=Tab[p.sommet];
	p.sommet--;
	return x;
}
//representation dynamique
typedef struct Cellule 
{
	int valeur;
	struct Cellule*suivant;
}Cellule;
typedef cellule*Pile;

int tete(Pile p) 
{
	//pré-condition: pile non vide !
	if(p==NULL) 
	{
		printf("Erreur: pile vide !\n");
		exit(-1); 
	}
	return p->valeur; 
}

pile empiler(int e,Pile p)
{
	cellule *ptr;
	ptr=(cellule*)malloc(sizeof(cellule));
	if(ptr==NULL)
	{
		exit(-1);
	}
	ptr->valeur = e;
	ptr->suivant = p;
	p=ptr;
	return p;
}

Pile depiler(Pile p) 
{
	cellule *ptr = p;
	if (p==NULL) 
	{
		printf("Erreur: pile vide !\n");
		exit(-1); 
	}
	p=p->suivant;
	free(ptr);
	return p;
}
