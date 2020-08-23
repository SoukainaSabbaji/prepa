#include <stdlib.h>
#include <stdio.h> 

//structure definition

typedef struct maillon
{
	int valeur;
	struct maillon *suivant;
}cellule;

//create linked list 

cellule *creer(int n)
{
	cellule *lis;
	lis = (cellule*)malloc(sizeof(cellule));
	lis->valeur = n;
		lis->suivant = NULL;
	return(lis);
}

//print the list 

void affichage(cellule *L)
{
	cellule *pc = L;
	while(pc != NULL)
	{
		printf("%d ",pc->valeur);
		pc = pc->suivant;
	}
}

//find the last element of a list 

cellule *dernier(cellule *L)
{
	cellule *p = L;
	if(p!=NULL)
	{
		while (p->suivant != NULL)
		{
			p = p->suivant;
		}
	}
	return p;
}

//add a new node at the beginning of the list 

cellule *insereD(int v , cellule *L)
{
	cellule *node; // create a new node
	node = (cellule*)malloc(sizeof(cellule));

	if(!node)
	{
		printf("allocation non reussie");
		exit(1);
	}
	node->valeur=v;
	node->suivant=L;//point the next of the new node to the head of the list
	L=node;//mark the node as the head of the list
	return(L);
}

//add a new node at the end of a list 

cellule *insereF(int v,cellule *L)
{
	cellule *node,*p; 
	node = (cellule*)malloc(sizeof(cellule));
	if(!node)
	{
		printf("allocation non reussie");
		exit(1);
	}
	node->valeur = v;
	node->suivant = NULL;//its the last node so it point to a null

	if (L==NULL)
		L=node;//if the list is empty let the added node be the only one there 
	else 
	{
		p=dernier(L);//we point p to the last case of the list
		p->suivant=node;//then the next of that last case is the node we are inserting so it would become the new last case 
	}
	return(L);
}

//function that returns the size of the list 

int taille(cellule *L)
{
	int k=0;
	cellule *p=L;// a pointer that points to the first node of the list 
	while(p!=NULL)
	{
		k++;
		p=p->suivant;
	}
	return k;
}

//function that searches for a certain element in a list 

cellule *recherche(cellule *L,int val)
{
	cellule *p=L;
	while((p!=NULL)&&(p->valeur!=val))
	{
		p=p->suivant;
	}
	return(p);
}

//function that deletes a node located at the beginning of the list 
//When removing the node at the beginning of the list there is no relinking 
//of nodes to be performed, since the first node has no preceding node

cellule *supprimerD(cellule *L)
{
	cellule *node;
	node = L;//node is also pointing to the beginning of the list
	L=L->suivant;// we move L a case to the front
	free(node);//we free the first case of the list
	return(L);
}

cellule * SuppMilieu (cellule *noeud, cellule *L) 
{

	cellule *precedent;
	precedent= L;	

while ((precedent->suivant != noeud)) //we search for the node 
{

	precedent=precedent->suivant;

}
precedent->suivant= noeud->suivant;//we skip the node we want to delete 
free(noeud);
return(L);
}
//To delete the last node of a linked list, find the second last node
//and make the next pointer of that node null.

cellule *suppF(cellule *L)
{
	cellule *ptr =L;
	cellule *t;
  	if(L->suivant==NULL)
  	{
    	free(L);
    	L=NULL;
  	}
  	else
  	{
     	while(ptr->suivant != NULL)
     	{
        	t=ptr;
        	ptr=ptr->suivant;
     }
    free(t->suivant);
    t->suivant=NULL; 
  }    
  return L;
}
  
void bubbleSort(cellule *start) 
{ 
    int swapped, i; 
    cellule *ptr1; 
    cellule  *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->suivant != lptr) 
        { 
            if (ptr1->valeur > ptr1->suivant->valeur) 
            {  
                swap(ptr1, ptr1->suivant); 
                swapped = 1; 
            } 
            ptr1 = ptr1->suivant; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
/* function to swap data of two nodes a and b*/
void swap(cellule *a,cellule *b) 
{ 
    int temp = a->valeur; 
    a->valeur = b->valeur; 
    b->valeur = temp; 
} 