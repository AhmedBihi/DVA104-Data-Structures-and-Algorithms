#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

Hashtable *create_table(int size)
{
    if(size < 1) return NULL;

    Hashtable *table = (Hashtable *)calloc(1, sizeof(Hashtable));
    if(table == NULL) return NULL;

    table->hashtable = (int *)calloc(size,sizeof(int));
    if(table->hashtable == NULL){
        free(table);
        return NULL;
    }

    table->size = size;

    return table;
}

int hash(Hashtable *table, int value, int i)
{
    int k = value % table->size + i;
    if(k >= table->size)
    {
        k = k - table->size;
    }
    return k;
}

void insert_hash(Hashtable *table, int value)
{
    int j;
    int i = 0;
    while(i < table->size)
    {
        j = hash(table, value, i);
        if(table->hashtable[j] == 0){
            table->hashtable[j] = value;
            return;
        }
        i++;
    }
}

int search_hash(Hashtable *table, int value)
{
    int j ,i = 0;
    while(table->hashtable[j] != 0 && i < table->size)
    {
        j = hash(table, value, i);
        if(table->hashtable[j] == value)
            return table->hashtable[j];
        i++;
    }
    return -1;
}

void destroy_table(Hashtable *table)
{
    free(table->hashtable);
    free(table);
}

unsigned int randomGen()
{
    unsigned int gissaTal;
    gissaTal = rand();
    return gissaTal;
}
