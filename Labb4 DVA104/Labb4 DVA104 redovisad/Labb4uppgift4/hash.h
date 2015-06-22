#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

typedef struct Hashtable{
    int size;
    int *hashtable;
}Hashtable;

Hashtable *create_table(int size);
int hash(Hashtable *table, int value, int i);
void insert(Hashtable *table, int value);
int search(Hashtable *table, int value);
void destroy_table(Hashtable *table);
unsigned int randomGen();

#endif // HASH_H_INCLUDED
