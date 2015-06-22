#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#include "hash.h"

// Uppgift 1
void sekvential_search(int haystack[], int key, int n)
{
    int i = 0;
    int found = 0;
    while(i < n)
    {
        if(key == haystack[i])
        {
            found = 1;
        }
        i++;
    }
}

// Uppgift 2
void sekvent_search(int haystack[], int key, int n)
{
    int i = 0;
    while(i < n)
    {
        if(key == haystack[i])
        {
            return;
        }
        i++;
    }
}

int main()
{
    Tree *tree = createTree();
    Hashtable *table5, *table50, *table500;
    FILE *fp50, *fp500, *fp5mil;
    clock_t tstart, tend;
    time_t t;
    srand((unsigned) time(&t));
    double favg;
    int data = 0, i = 0, search, value, found;
    int array50k[50000], *array500k, *array5mil;
    array500k = malloc(500001 * sizeof(int));
    array5mil = malloc(5000001 * sizeof(int));
    if(tree == NULL)
        printf("Memory allocation failed...");
    fp50 = fopen("50tus.txt", "r");
    fp500 = fopen("500tus.txt", "r");
    fp5mil = fopen("5mil.txt", "r");
    if(fp50 == NULL || fp500 == NULL|| fp5mil == NULL)
    {
        fprintf(stderr, "error\n");
        return 1;
    }
    system("color 3");
    table5 = create_table(50000000);
    table50 = create_table(500000);
    table500 = create_table(5000000);

    /*50k*/
    printf("\n50k insert, balance and search!\n");
    printf("Insert: 50k ");
    tstart = clock(); // start
    for(i = 0; i < 50000; ++i)
    {
        fscanf(fp50,"%d\n", &data);
        insert(tree, data);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    tree_to_arr(tree);
    printf("Searching 100x in 50k ");
    tstart = clock(); // start
    find_tree(tree);
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    clear_tree(tree);

    /*500k*/
    printf("\n500k insert, balance and search!\n");
    printf("Insert: 500k ");
    tstart = clock(); // start
    for(i = 0; i < 500000; ++i)
    {
        fscanf(fp500,"%d\n", &data);
        insert(tree, data);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    tree_to_arr(tree);
    printf("Searching 100x in 500k ");
    tstart = clock(); // start
    find_tree(tree);
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    clear_tree(tree);

    /*5mille*/
    printf("\n5 million insert, balance and search!\n");
    printf("Insert: 5 million ");
    tstart = clock(); // start
    for(i = 0; i < 5000000; ++i)
    {
        fscanf(fp5mil,"%d\n", &data);
        insert(tree, data);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    tree_to_arr(tree);
    printf("Searching 100x in 5 million ");
    tstart = clock(); // start
    find_tree(tree);
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    clear_tree(tree);

    /*50k sekvens*/
    printf("\nSekvential insert 50k!\n");
    tstart = clock(); // start
    for(i = 0; i<50000; i++)
    {
        fscanf(fp50, "%d\n", &array50k[i]);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    printf("Sekvential search 50k, 100x!\n");
    tstart = clock(); // start
    for(i = 0; i<100; i++)
    {
        search = randomGen();
        sekvential_search(array50k, search, 50000);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    printf("Sekvential search 50k, 100x(o)!\n");
    tstart = clock(); // start
    for(i = 0; i<100; i++)
    {
        search = randomGen();
        sekvent_search(array50k, search, 50000);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);

    /*500k sekvens*/
    printf("\nSekvential insert 500k!\n");
    tstart = clock(); // start
    for(i = 0; i<500000; i++)
    {
        fscanf(fp500, "%d\n", &array500k[i]);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    printf("Sekvential search 500k, 100x!\n");
    tstart = clock(); // start
    for(i = 0; i<100; i++)
    {
        search = randomGen();
        sekvential_search(array500k, search, 500000);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    printf("Sekvential search 500k, 100x(o)!\n");
    tstart = clock(); // start
    for(i = 0; i<100; i++)
    {
        search = randomGen();
        sekvent_search(array500k, search, 500000);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);

    /*5mille seq*/
    printf("\nSekvential insert 5 million!\n");
    tstart = clock(); // start
    for(i = 0; i<5000000; i++)
    {
        fscanf(fp5mil, "%d\n", &array5mil[i]);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    printf("Sekvential search 5 million, 100x!\n");
    tstart = clock(); // start
    for(i = 0; i<100; i++)
    {
        search = randomGen();
        sekvential_search(array5mil, search, 5000000);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);
    printf("Sekvential search 5 million, 100x(o)!\n");
    tstart = clock(); // start
    for(i = 0; i<100; i++)
    {
        search = randomGen();
        sekvent_search(array5mil, search, 5000000);
    }
    tend = clock(); // end
    favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
    printf("Avg. execution time: %g sec\n",favg);

    /*Hash 500k*/
    printf("\nHash insert 50k!\n");
    tstart = clock(); // start
    for(i = 0; i<50000; i++){
        fscanf(fp500, "%d\n", &value);
        insert_hash(table50, value);
    }
        tend = clock(); // end
        favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
        printf("Avg. execution time: %g sec\n",favg);

    /*Hash 500k*/
    printf("\nHash insert 500k!\n");
    tstart = clock(); // start
    for(i = 0; i<500000; i++){
        fscanf(fp500, "%d\n", &value);
        insert_hash(table500, value);
    }
        tend = clock(); // end
        favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
        printf("Avg. execution time: %g sec\n",favg);

    /*Hash 5 mille*/
    printf("\nHash insert 5 million!\n");
    tstart = clock(); // start
    for(i = 0; i<5000000; i++){
        fscanf(fp5mil, "%d\n", &value);
        insert_hash(table5, value);
    }
        tend = clock(); // end
        favg = ((double)(tend - tstart))/CLOCKS_PER_SEC;
        printf("Avg. execution time: %g sec\n",favg);

    destroy_table(table5);
    destroy_table(table50);
    destroy_table(table500);
    destroyTree(tree);
    return 0;
}
