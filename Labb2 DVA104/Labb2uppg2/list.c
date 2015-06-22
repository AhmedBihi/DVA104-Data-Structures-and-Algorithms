/***********************************************************
* Lista & K�, Labb 2 uppgift 2                             *
* ADT L�nkad Lista (List.c)                                *
*                                                          *
* Datastrukturer, algoritmer och programkonstruktion,DVA104*
* Ahmed Bihi                                               *
* 19920613                                                 *
* abi14002                                                 *
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

/*Skapar en tom lista*/
List *createList()
{
    List *myList =(List *)calloc(1, sizeof(List));
    if (myList == NULL)
    {
        return NULL;
    }
    printf("List created!\n");
    return myList;
}

/*Allokerar minne f�r en nod och l�gger in ett v�rde*/
Node *createNode(int data)
{
    Node *newNode = (Node *)calloc(1, sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory for new node could not be allocated");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*Genererar random tal f�r f�rger i konsolen*/
void randomGen(char **string)
{
    int random;
    srand( time(NULL));
    random = rand()%9;
    sprintf(*string, "color %d", random);
}

/*Kollar hur m�nga noder det finns i listan*/
int noOfNodesInList(List *myList)
{
    Node *temp = myList->head;
    int i = 0;
    while(temp!=NULL)
    {
        i++;
        temp = temp->next;
    }
    return (i);
}

/*L�gger till en nod f�rst i listan*/
void insert_first(List *myList, Node *newNode)
{
    newNode->next = myList->head;
    myList->head = newNode;
}

/*L�gger till en nod sist i listan*/
void insert_last(List *myList, Node *newNode)
{
    Node *temp;
    newNode->next = NULL;
    if(myList->head == NULL)
    {
        myList->head = newNode;
        temp = newNode;
    }
    else
    {
        temp = myList->head; // b�rjar p� starten av listan
        while(temp->next != NULL) // Loopar till slutet av listan
        {
            temp = temp->next; // S�tter temp till pekar v�rden
        }
        temp->next = newNode; // Matar in data i slutet av listan
    }
}

/*L�gger till en nod i angiven position*/
int insert_position(List *myList, Node *newNode, int pos)
{
    int i;
    Node *right, *left, *temp;
    right = myList->head;
    if(noOfNodesInList(myList) == 0) //kollar s� listan inte �r tom
        return -1;
    else if(noOfNodesInList(myList) == 2 && pos == 2) //kollar s� listan inte �r tom
    {
        temp = newNode;
        left = right->next;
        right = left->next;
        left->next = temp;
        right = temp;
    }
    else
    {
        for(i=1; i<pos; i++) // Stannar n�r positionen har hittats
        {
            left = right; // g�r igenom listan fr�n v�nster till h�ger
            right = right->next;
        }Node *temp = myList->head;
    myList->head = temp->next;
    free(temp);
        temp = newNode; // S�tter in newNode i temp->data
        left->next=temp; // pekar left->next p� den nya noden
        left = temp; // flyttar left till den nya noden
        left->next = right; // pekar fr�n nya noden till right
    }
    return 0;
}

/*Tar bort det f�rsta elementen i listan*/
void remove_first(List *myList)
{
    Node *temp = myList->head;
    if(noOfNodesInList(myList) == 1)
        emptyList(myList);
    if(temp == NULL){
        printf("List is empty!\n");
        return;
    }
    // S�tter f�rsta noden till andra noden i listan och frig�r minnet
    myList->head = temp->next;
    free(temp);
}

/*Tar bort det sista elementet i listan*/
void remove_last(List *myList)
{
    Node *temp, *last;
    temp = myList->head; // b�rjar p� starten av listan
    if(noOfNodesInList(myList) == 0)
        printf("The list is empty!\n");
    if(noOfNodesInList(myList) == 1)
        remove_first(myList);
    while(temp->next != NULL) // Loopar till slutet av listan
    {
        last = temp;
        temp = temp->next; // S�tter temp till pekar v�rden
    }
    free(last->next);
    last->next = NULL;
}

/*Raderar en nod p� given position*/
int remove_position(List *myList, int pos)
{
    int i;
    Node *right, *left, *del;
    right = myList->head;
    if(noOfNodesInList(myList) == 0) //kollar s� listan inte �r tom
        return -1;
    else if(pos == 0)
        remove_last(myList);
    else if(pos == 1)
        remove_first(myList);
    else
    {
        for(i=1; i<pos; i++) // Stannar n�r positionen har hittats
        {
            left = right; // g�r igenom listan fr�n v�nster till h�ger
            right = right->next;
        }
        del = right; // Noden som ska raderas
        right = right->next; // Noden brevid den som ska raderas
        left->next = right; // V�nster om den raderade pekar till h�ger om raderad
        free(del);
    }

    return 0;
}


/* S�ker efter ett tal och skriver ut om talet f�rekommer*/
void search(List *myList, int search)
{
    int count = 0;
    Node *iterator = myList->head;
    if(noOfNodesInList(myList) == 0) // Kollar om det finns noder i listan
        printf("\nThe list is empty");
    else
    {
        while(iterator->next != NULL)
        {
            if(iterator->data == search)
                count++; //R�kning f�r hur m�nga g�nger s�k talet f�rekommer
            iterator = iterator->next;
        }
        if(count > 0) // valt att bara skriva om den finns eller ej
            printf("Occurs in list!\n");
        else
            printf("Does not occur in list!\n");
    }
}

/* Skriver ut alla noder i listan */
void printList(List *myList)
{
    Node *iterator = myList->head;
    if(noOfNodesInList(myList) == 0) // Kollar om det finns noder i listan
        printf("\nThe list is empty!\n");
    else
    {
        printf("\nThe list: ");
        do
        {
            printf("%d   ", iterator->data);
            iterator = iterator->next;
        }
        while(iterator != NULL);
    }
}

/* K�r free() p� hela listan */
void emptyList(List *myList)
{
    Node *iterator = myList->head; // start
    Node *temp; // Temporar variabel
    while(iterator != NULL)
    {
        temp = iterator; // Tar iteratorns varde som ska frigoras
        iterator = iterator->next; //flyttar runt i listan
        free(temp); // Frigor det allokerade minnet
    }
    //myList->head = NULL; // Anger att listan ar tom
}

/*Tar bort alla element i listan och frig�r listan*/
void listDestroy(List *myList)
{
    emptyList(myList);
    free(myList);
}
