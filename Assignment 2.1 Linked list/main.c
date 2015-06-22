/***********************************************************
* Lista & Kö, Labb 2 uppgift 1                             *
* ADT Länkad Lista (Meny)                                  *
*                                                          *
* Datastrukturer, algoritmer och programkonstruktion,DVA104*
* Ahmed Bihi                                               *
* 19920613                                                 *
* abi14002                                                 *
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Här test kör jag alla funktioner jag skapat i en meny som ändrar färg efter
   varje menyval, i menyn kan man testa alla funktioner genom meny alternativen */
int main()
{
    List *newList;
    Node *newNode;
    int value, position, menu;
    char *random;
    if((newList = createList()) == NULL)
        return 0;

    printf("\nWelcome to my linked list!");

    while(1){
    randomGen(&random);
    system(random);
    printf("\nMenu \n#1 Add element. \n#2 Remove element.\n#3 Search\n");
    printf("#4 Empty list\n#5 Print list\n#6 Exit program \n>");
    scanf("%d", &menu);
    fflush(stdin);
    switch(menu)
    {
    case 1:
        while(1)
        {
            printf("Insert value to node: ");
            scanf("%d", &value);
            if(value == -1)
                break;
            if((newNode = createNode(value)) == NULL)
                return 0;
            printf("What position?(1 for first, 0 for last): ");
            scanf("%d", &position);
            if(position == 1)
                insert_first(newList, newNode);
            else if(position == 0)
                insert_last(newList, newNode);
            else if(position > noOfNodesInList(newList)){
                printf("Only %d elements in list\n", noOfNodesInList(newList));
            }
            else
            {
                if(insert_position(newList, newNode, position) == -1)
                {
                    printf("There are no elements in this list\n");
                    break;
                }
            }
            fflush(stdin);
        }
        break;

    case 2:
        printf("Remove at what position? (1 for first, 0 for last): ");
        scanf("%d", &position);
        if(position == 1)
            remove_first(newList);
        else if(position == 0)
            remove_last(newList);
        else{
            if(remove_position(newList, position) == -1)
            {
                printf("There are no elements in this list\n");
            }
        }
        fflush(stdin);
        break;

    case 3:
        printf("Search for a number: ");
        scanf("%d", &position);
        search(newList, position);
        break;

    case 4:
        if(noOfNodesInList(newList) > 0){
            emptyList(newList);
            printf("\nList has been emptied!");
        }
        else{
            printf("List is empty!\n");
        }
        break;

    case 5:
        printList(newList);
        break;

    case 6:
        listDestroy(newList);
        printf("\nLinked list destroyed...");
        return 0;
        break;
    }
    printf("\nPress any key to continue. . .\n");
    getch();
    }
    return 0;
}
