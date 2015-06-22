/***********************************************************
* Lista & Kö, Labb 2 uppgift 2                             *
* ADT Länkad Lista (List.c)                                *
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

/*Allokerar minne för en nod och lägger in ett värde*/
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

/*Genererar random tal för färger i konsolen*/
void randomGen(char **string)
{
    int random;
    srand( time(NULL));
    random = rand()%9;
    sprintf(*string, "color %d", random);
}

/*Kollar hur många noder det finns i listan*/
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

/*Lägger till en nod först i listan*/
void insert_first(List *myList, Node *newNode)
{
    newNode->next = myList->head;
    myList->head = newNode;
}

/*Lägger till en nod sist i listan*/
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
        temp = myList->head; // börjar på starten av listan
        while(temp->next != NULL) // Loopar till slutet av listan
        {
            temp = temp->next; // Sätter temp till pekar värden
        }
        temp->next = newNode; // Matar in data i slutet av listan
    }
}

/*Lägger till en nod i angiven position*/
int insert_position(List *myList, Node *newNode, int pos)
{
    int i;
    Node *right, *left, *temp;
    right = myList->head;
    if(noOfNodesInList(myList) == 0) //kollar så listan inte är tom
        return -1;
    else if(noOfNodesInList(myList) == 2 && pos == 2) //kollar så listan inte är tom
    {
        temp = newNode;
        left = right->next;
        right = left->next;
        left->next = temp;
        right = temp;
    }
    else
    {
        for(i=1; i<pos; i++) // Stannar när positionen har hittats
        {
            left = right; // går igenom listan från vänster till höger
            right = right->next;
        }Node *temp = myList->head;
    myList->head = temp->next;
    free(temp);
        temp = newNode; // Sätter in newNode i temp->data
        left->next=temp; // pekar left->next på den nya noden
        left = temp; // flyttar left till den nya noden
        left->next = right; // pekar från nya noden till right
    }
    return 0;
}

/*Tar bort det första elementen i listan*/
void remove_first(List *myList)
{
    Node *temp = myList->head;
    if(noOfNodesInList(myList) == 1)
        emptyList(myList);
    if(temp == NULL){
        printf("List is empty!\n");
        return;
    }
    // Sätter första noden till andra noden i listan och frigör minnet
    myList->head = temp->next;
    free(temp);
}

/*Tar bort det sista elementet i listan*/
void remove_last(List *myList)
{
    Node *temp, *last;
    temp = myList->head; // börjar på starten av listan
    if(noOfNodesInList(myList) == 0)
        printf("The list is empty!\n");
    if(noOfNodesInList(myList) == 1)
        remove_first(myList);
    while(temp->next != NULL) // Loopar till slutet av listan
    {
        last = temp;
        temp = temp->next; // Sätter temp till pekar värden
    }
    free(last->next);
    last->next = NULL;
}

/*Raderar en nod på given position*/
int remove_position(List *myList, int pos)
{
    int i;
    Node *right, *left, *del;
    right = myList->head;
    if(noOfNodesInList(myList) == 0) //kollar så listan inte är tom
        return -1;
    else if(pos == 0)
        remove_last(myList);
    else if(pos == 1)
        remove_first(myList);
    else
    {
        for(i=1; i<pos; i++) // Stannar när positionen har hittats
        {
            left = right; // går igenom listan från vänster till höger
            right = right->next;
        }
        del = right; // Noden som ska raderas
        right = right->next; // Noden brevid den som ska raderas
        left->next = right; // Vänster om den raderade pekar till höger om raderad
        free(del);
    }

    return 0;
}


/* Söker efter ett tal och skriver ut om talet förekommer*/
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
                count++; //Räkning för hur många gånger sök talet förekommer
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

/* Kör free() på hela listan */
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

/*Tar bort alla element i listan och frigör listan*/
void listDestroy(List *myList)
{
    emptyList(myList);
    free(myList);
}
