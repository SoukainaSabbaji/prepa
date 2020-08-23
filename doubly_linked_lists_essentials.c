#include <stdio.h>
#include <stdlib.h> 

//structure definition 

typedef struct maillon
{
    int valeur;
    struct maillon *precedent;
    struct maillon *suivant;
}cellule;

cellule *head;

cellule *creer(int v)
{
    cellule *L;
    L = (cellule*)malloc(sizeof(cellule));
    L->valeur=v;
    L->precedent=NULL;
    L->suivant=NULL;

    return(L);
}

void affichage(cellule *L)
{
    cellule *p=L;
    while(p!=NULL)
    {
        printf("%d",p->valeur);
        p=p->suivant;
    }

}

cellule *ajouterd(int v , cellule *L)
{
    cellule *node;//create the new node 
    node=(cellule*)malloc(sizeof(cellule));
    node->valeur=v;
    node->precedent=NULL;//its situated at the beginning of the list
    node->suivant=L;//link the next pointer to the first case of the list
    if(L!=NULL)
    {
        L->precedent = node;//change previous of head node to the new node 
    }
    L=node;//move the head to point to the new node 
    return(L);
}

cellule *ajouterF(cellule *L,int v)
{
    cellule *node,*p;
    node=(cellule*)malloc(sizeof(cellule));
    node->valeur=v;
    node->suivant=NULL;
    if(L==NULL)
    L=node;
    else
    {
        p=dernier(L);
        p->suivant=node;
    }
    return(L);
} 

cellule *supprD(cellule *L)
{
    cellule *ptr=L;
    if(ptr==NULL)
    {
        printf("liste vide !");
    }
    else
    {
        L=L->suivant;
    if(L!=NULL)
    L->precedent=NULL;
    }
    free(ptr);
    return(L);    
}


cellule *dernier(cellule *L)
{
    cellule *ptr=L;
    if(ptr!=NULL)
    {
        while(ptr->suivant != NULL)
        {
           ptr = ptr->suivant; 
        }
        
    }
    return (ptr);
}

void supprF(cellule *L)
{
    cellule *NodeToDel;
 
    if(L == NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel = L;
        L = L->precedent;    // move the previous address of the last node to 2nd last node
        L->suivant = NULL;     // set the next address of last node to NULL
        free(NodeToDel);            // delete the last node
    }
}

void DlListDeleteAnyNode(int pos,cellule*L)
{
    cellule *curNode;
    int i;
 
    curNode = L;
    for(i=1; i<pos && curNode!=NULL; i++)
    {
        curNode = curNode->suivant;
    }
 
    if(pos == 1)
    {
        supprD(L);
    }
    else if(curNode == dernier(L))
    {
        supprF(L);
    }
    else if(curNode != NULL)
    {
        curNode->precedent->suivant = curNode->suivant;
        curNode->suivant->precedent = curNode->precedent;
 
        free(curNode); //Delete the n node
    }
    else
    {
        printf(" The given position is invalid!\n");
    }
} 




