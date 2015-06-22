/***********************************************************
* Lista & Kö, Labb 2 uppgift 2                             *
* ADT Länkad Lista (main)                                  *
*                                                          *
* Datastrukturer, algoritmer och programkonstruktion,DVA104*
* Ahmed Bihi                                               *
* 19920613                                                 *
* abi14002                                                 *
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"
#include "List.h"

int main()
{
    int data, meny;
    Queue *queue;
    system("color 3");
    queue = queueCreate();
    while(1){
    printf("\n   MENU \n#1 Enqueue\n#2 Dequeue\n#3 Print\n#4 Front\n#5 Size\n#6 Empty\n#7 Quit\n");
    scanf("%d", &meny);
        switch(meny)
        {
        case 1:
            while(1){
            printf("Insert number to queue: ");
            scanf("%d", &data);
            if(data == -1)
                break;
            enqueue(queue, data);
            }
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            printQueue(queue);
            break;
        case 4:
            printf("Front: %d",frontelement(queue));
            break;
        case 5:
            printf("Size of queue: %d",queueSize());
            break;
        case 6:
            emptyQueue(queue);
            break;
        case 7:
            destroyQueue(queue);
            return 0;
        }
    }

    return 0;
}
