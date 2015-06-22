/***********************************************************
* Lista & Kö, Labb 2 uppgift 2                             *
* ADT Länkad Lista (FIFO.h)                                *
*                                                          *
* Datastrukturer, algoritmer och programkonstruktion,DVA104*
* Ahmed Bihi                                               *
* 19920613                                                 *
* abi14002                                                 *
***********************************************************/

#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED
#include "list.h"

typedef List Queue;

Queue *queueCreate();
void dequeue(Queue *myQueue);
void enqueue(Queue *myQueue, int data);
void printQueue(Queue *myQueue);
int frontelement(Queue *q);
int queueSize(void);
void emptyQueue(Queue *myQueue);
void destroyQueue(Queue *myQueue);

#endif // FIFO_H_INCLUDED
