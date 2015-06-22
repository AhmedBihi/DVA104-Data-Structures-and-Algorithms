/***********************************************************
* Lista & Kö, Labb 2 uppgift 2                             *
* ADT Länkad Lista (FIFO.c)                                *
*                                                          *
* Datastrukturer, algoritmer och programkonstruktion,DVA104*
* Ahmed Bihi                                               *
* 19920613                                                 *
* abi14002                                                 *
***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "FIFO.h"

int count = 0; // Håller reda på köns storlek

/*Skapar en lista*/
Queue *queueCreate(void)
{
    return createList();
}

/*Tar bort det första elementen från listan, p.s har försökt återanvända
  remove_first från list.h men fick massa konstiga buggar */
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
            count--; // räkning för queueSize()
        }
        else{
            printf("\nDequed: %d", front->data);
            free(myQueue->head);
            myQueue->head = NULL;
            myQueue->last = NULL;
            count--; // räkning för queueSize()
        }
    }

}

/*Skapar en node och sätter in den sist i kön*/
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
    count++; // räkning för queueSize()
}

/*Returnerar det första elementet i kön*/
int frontelement(Queue *q)
{
    if((q->head != NULL) && (q->last != NULL))
        return(q->head->data);
    else
        return 0;
}

/*Returnerar storleken på kön*/
int queueSize(void)
{
    return count;
}

/*Printar ut alla element i kön*/
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

/*Rensar kön på element*/
void emptyQueue(Queue *myQueue)
{
    emptyList(myQueue);
}

/*Rensar kön på element och tar bort listan*/
void destroyQueue(Queue *myQueue)
{
    listDestroy(myQueue);
}
