#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#include "hash.h"

unsigned int randomGen()
{
    unsigned int gissaTal;
    gissaTal = rand()%9999999999;
    return gissaTal;
}

// Uppgift 1
void sekvential_search(int haystack[], int key, int n)
{
    int i = 0;
    int found = 0;
    while(i < n)
    {
        if(key == haystack[i]){
            found = 1;
        }
        i++;
    }
    if(found == 1)
        printf("%d is in array!\n", key);
    else
        printf("%d is not in array!\n", key);
}

// Uppgift 2
void sekvent_search(int haystack[], int key, int n)
{
    int i = 0;
    while(i < n)
    {
        if(key == haystack[i]){
            printf("%d is in array!\n", key);
            return;
        }
        i++;
    }
    printf("%d is not in array!\n", key);
}

int main()
{
    FILE *fp;

	clock_t tstart, tend;
	time_t t;
    srand((unsigned) time(&t));
	double favg;
    int i, menu;
    int search;
    int array50k[50000], *array500k, *array5mil;
    array500k = malloc(500001 * sizeof(int));
    array5mil = malloc(5000001 * sizeof(int));
    system("color 3");

    while(1){
        printf("Menu\n#1 Insert million\n#2 Insert 500 grand\n#3 50 grand\n");
        printf("#4 Insert million(Opt)\n#5 Insert 500 grand(Opt)\n#6 50 grand(Opt)\n>");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            fp = fopen("5mil.txt", "r");
            if(fp == NULL)
                printf("error!\n");
            tstart = clock(); // start
            for(i = 0; i<5000000; i++){
                fscanf(fp, "%d\n", &array5mil[i]);
            }
            search = randomGen();
            sekvential_search(array5mil, search, 5000000);
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 2:
            fp = fopen("500tus.txt", "r");
            if(fp == NULL)
                printf("error!\n");
            tstart = clock(); // start
            for(i = 0; i<500000; i++){
                fscanf(fp, "%d\n", &array500k[i]);
            }
            search = randomGen();
            sekvential_search(array500k, search, 500000);
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 3:
            fp = fopen("50tus.txt", "r");
            if(fp == NULL)
                printf("error!\n");
            tstart = clock(); // start
            for(i = 0; i<50000; i++){
                fscanf(fp, "%d\n", &array50k[i]);
            }
            search = randomGen();
            sekvential_search(array50k, search, 50000);
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 4:
            fp = fopen("5mil.txt", "r");
            if(fp == NULL)
                printf("error!\n");
            tstart = clock(); // start
            for(i = 0; i<5000000; i++){
                fscanf(fp, "%d\n", &array5mil[i]);
            }
            search = randomGen();
            sekvent_search(array5mil, search, 5000000);
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 5:
            fp = fopen("500tus.txt", "r");
            if(fp == NULL)
                printf("error!\n");
            tstart = clock(); // start
            for(i = 0; i<500000; i++){
                fscanf(fp, "%d\n", &array500k[i]);
            }
            search = randomGen();
            sekvent_search(array500k, search, 500000);
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 6:
            fp = fopen("50tus.txt", "r");
            if(fp == NULL)
                printf("error!\n");
            tstart = clock(); // start
            for(i = 0; i<50000; i++){
                fscanf(fp, "%d\n", &array50k[i]);
            }
            search = randomGen();
            sekvent_search(array50k, search, 50000);
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        default:
            printf("Wrong number!\n");
            break;
        }
        fflush(stdin);
    }

    return 0;
}
