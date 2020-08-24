#include <stdlib.h>
#include <stdio.h>
#define N 50

//struct definition 

typedef struct c
{
    int Tab[N];
    int tete;
    int queue;
}File;

// lors de l'initialisation queue = tete = 0

File initialisation()
{
    File f;
    f.tete = 0;
    f.queue = 0;
    return f;
}

//File est vide => tete = queue
//file est pleine queue = N (dimension)
int est_vide(File f)
{
    if(f.tete == f.queue)
    return 1;
    else
    return 0;
}
//fonction enfiler 
//1-check if its full or not
//2-queue = new element
//3-queue++ 
//4-return file

File enfiler(File f , int val)
{
    if(F.queue >= N)
    exit(-1);
    f.Tab[f.queue] = val;
    f.queue++;
    return f;
}

//fonction defiler
//1-check if empty
//f.tete++
//return f
File defiler(File f)
{
    if(est_vide(f)==1)
    exit(-1);
    f.tete++;
    return f;
}
/*----------------------------DYNAMIC REPRESENTATION----------------------------------*/
//struct and types definition
typedef struct cellule
{
    int valeur;
    struct cellule *suivant;
}cellule;

typedef struct 
{
    cellule *tete;
    cellule *queue;
}File;
File F;

File initialise(File f)
{
    f.tete = NULL;
    f.queue = NULL;
    return f;
}

int sommet(File f)
{
    if(f.tete == f.queue)//file vide
    exit(-1);
    return(f.tete)->valeur;
}

//fonction enfiler 
File enfiler(File f ,int v)
{
    cellule *ptr; //create the new element
    ptr=(cellule*)malloc(sizeof(cellule));
    if(ptr==NULL)
    exit(-1);//allocation non reussie
    ptr->valeur = v ;//put data in it 
    ptr->suivant = NULL;//and point its next to null since its gonna be at the end of the Q
    if(f.queue == NULL)//if its empty make the new element both the start n the end of the Q
    f.tete = f.queue = ptr; 
    else 
    f.queue->suivant = ptr;//make the element after the end of the queue = new element
    f.queue = ptr;//make the new element the last elemet in the Q 
    return f; 
}
//fonction defiler
File defiler(File f)
{
    cellule *p; //ptr to the head of the list 
    if(f.tete == NULL)
    {
      exit(-1);  
    }
    p = f.tete;
    f.tete = (f.tete)->suivant;
    free(p);
    if(f.tete == NULL)
    f.queue = NULL;
    return f;
}
//end 