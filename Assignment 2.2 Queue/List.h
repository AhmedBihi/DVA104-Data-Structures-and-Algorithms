/***********************************************************
* Lista & Kö, Labb 2 uppgift 2                             *
* ADT Länkad Lista (List.c)                                *
*                                                          *
* Datastrukturer, algoritmer och programkonstruktion,DVA104*
* Ahmed Bihi                                               *
* 19920613                                                 *
* abi14002                                                 *
***********************************************************/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct List{
    Node *head;
    Node *last;
} List;

List *createList();
Node *createNode(int data);
void randomGen(char **string);
int noOfNodesInList(List *myList);
void insert_first();
void insert_last(List *myList, Node *newNode);
int insert_position(List *myList, Node *newNode, int pos);
void remove_first(List *myList);
void remove_last(List *myList);
int remove_position(List *myList, int pos);
void search(List *myList, int search);
void printList(List *myList);
void emptyList(List *myList);
void listDestroy(List *myList);

#endif // LIST_H_INCLUDED
