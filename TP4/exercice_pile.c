#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct
{
	int Tab[N];
	int sommet;
}pile;

pile *init()
{
	pile *p;
	p=(pile*)malloc(sizeof(pile));
	p->sommet=-1;
	return p;
}

int estvide(pile *p)
{
	if(p->sommet == -1)
		return 1;
	else 
		return 0;
}

void empiler(pile *p,int elm)
{
	if(p->sommet >= N)
		exit(-1);
	else 
	{
		p->sommet++;
		p->Tab[p->sommet]=elm;
	}
}

int depiler(pile *p)
{
	int elm;
	if(estvide(p)==1)
		exit(-1);
	else 
	{
		elm = p->Tab[p->sommet];
		p->sommet--;}
	return elm;
}

void afficher(pile *p)
{
	int i;
	for (i=p->sommet;i>=0;i--)
	{
		printf("%d \n",p->Tab[i]);
	}
}

int sommet(pile *p)
{
	if(estvide(p)==1)
		return 62;
	else 
		return (p->Tab[p->sommet]);
}

void deplacer(pile *p1,pile *p2)
{
	pile *p3;
	int s;
	p3=init();
	while (estvide(p1) != 1)
	{
		s=depiler(p1);
		if(s%2 == 0)
			empiler(p3,s);
		else 
			empiler(p2,s);
	}
	while(estvide(p3) != 1)
	{
		empiler(p2,depiler(p3));
	}
}

int main()
{
	int dim,i,s,sum;
	pile *p1,*p2,*p3;
	p1=init();
	p2=init();
	printf("donnez le nombre de valeurs \n");
	scanf("%d",&sum);
	printf("faites le saisi des valeurs \n");
	for (i=0 ; i < sum ;i++)
	{
		scanf("%d",&s);
		empiler(p1,s);
	}
	printf("voici votre pile \n");
	afficher(p1);
	sum=sommet(p1);
	printf("le sommet de votre pile est %d \n",sum);
	deplacer(p1,p2);
	printf("votre pile apres modification \n");
	afficher(p2);
	return 0;
}


