/***********************************************************
* Lista & K�, Labb 2 uppgift 2                             *
* ADT L�nkad Lista (FIFO.c)                                *
*                                                          *
* Datastrukturer, algoritmer och programkonstruktion,DVA104*
* Ahmed Bihi                                               *
* 19920613                                                 *
* abi14002                                                 *
***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "FIFO.h"

int count = 0; // H�ller reda p� k�ns storlek

/*Skapar en lista*/
Queue *queueCreate(void)
{
    return createList();
}

/*Tar bort det f�rsta elementen fr�n listan, p.s har f�rs�kt �teranv�nda
  remove_first fr�n list.h men fick massa konstiga buggar */
void dequeue(Queue *myQueue)
{
    Node *front = myQueue->head;
    if(front == NULL)
    {
        printf("\nQueue is empty!");
    }
    else{
        if(front->next != NULL){
            front = front->next;
            printf("\nDequed: %d", myQueue->head->data);
            free(myQueue->head);
            myQueue->head = front;
            count--; // r�kning f�r queueSize()
        }
        else{
            printf("\nDequed: %d", front->data);
            free(myQueue->head);
            myQueue->head = NULL;
            myQueue->last = NULL;
            count--; // r�kning f�r queueSize()
        }
    }

}

/*Skapar en node och s�tter in den sist i k�n*/
void enqueue(Queue *q, int data)
{
    Node *temp;
    if(q->last == NULL){
        q->last = createNode(data);
        q->head = q->last;
    }
    else{
        temp = createNode(data);
        q->last->next = temp;
        q->last = temp;
    }
    count++; // r�kning f�r queueSize()
}

/*Returnerar det f�rsta elementet i k�n*/
int frontelement(Queue *q)
{
    if((q->head != NULL) && (q->last != NULL))
        return(q->head->data);
    else
        return 0;
}

/*Returnerar storleken p� k�n*/
int queueSize(void)
{
    return count;
}

/*Printar ut alla element i k�n*/
void printQueue(Queue *myQueue)
{
    Node *front = myQueue->head;
    if((front == NULL) && (myQueue->last == NULL)){
        printf("\nQueue is empty");
        return;
    }
    while(front != myQueue->last){
        printf("%d ", front->data);
        front = front->next;
    }
    if(front == myQueue->last)
        printf("%d", front->data);
}

/*Rensar k�n p� element*/
void emptyQueue(Queue *myQueue)
{
    emptyList(myQueue);
}

/*Rensar k�n p� element och tar bort listan*/
void destroyQueue(Queue *myQueue)
{
    listDestroy(myQueue);
}
