#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash.h"

int main()
{
    FILE *fp;
    Hashtable *table;
	clock_t tstart, tend;
	time_t t;
    srand((unsigned) time(&t));
	double favg;
    int i, menu, value, found;
    int searchNum;
    system("color 3");
    table = create_table(50000001);

    while(1){
        printf("Menu\n#1 Insert million\n#2 Insert 500 grand\n#3 Insert 50 grand\n");
        printf("#4 Search 100x\n#5 Destroy table\n>");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            fp = fopen("5mil.txt", "r");
            if(fp == NULL)
                printf("error!\n");

            tstart = clock(); // start
            for(i = 0; i<5000000; i++){
                fscanf(fp, "%d\n", &value);
                insert(table, value);
            }
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
                fscanf(fp, "%d\n", &value);
                insert(table, value);
            }
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
                fscanf(fp, "%d\n", &value);
                insert(table, value);
            }
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 4:
            tstart = clock(); // start
            for(i=0;i<100;i++){
                searchNum = randomGen();
                found = search(table, searchNum);
                if(found == searchNum)
                    printf("Found %d!\n", found);
                else
                    printf("Not found!\n");

            }
            tend = clock(); // end

            /* compute average execution time */
            favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
            printf("Avg. execution time: %g sec\n",favg);
            break;
        case 5:
            destroy_table(table);
            break;
        default:
            printf("Wrong number!\n");
            break;
        }
        fflush(stdin);
    }

}
