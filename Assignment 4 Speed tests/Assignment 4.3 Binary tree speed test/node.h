#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/*Precondition: minne finns tillgänglig för allokering
  Postcondition: ny nod skapad
  return: */
Node *createNode(int data);

/*Precondition:
  Postcondition: sätter in nya noden sorterat i trädet
  return: */
Node *insertSorted(Node *subTree, Node *newNode);

/*Precondition:
  Postcondition:
  return: return noden om noden finns*/
Node *find(Node *node, int n);

/*Precondition:
  Postcondition:
  return: return noden om noden finns*/
Node *removeNode(Node *node, int data);

/*Precondition:
  Postcondition:
  return: returnerar ett balanserat träd*/
Node *arr_to_tree(int arr[], int start, int end);

/*Precondition:
  Postcondition:
  return: Den minsta noden i höger delträd */
int smallest(Node *node);

/*Precondition:
  Postcondition:
  Return:*/
void traverse_postorder(Node *node, void (*f)(void*));

/*Precondition: Träd finns
  Postcondition:
  return: max höjden på trädet */
int max_height(Node *node);

/*Precondition: Träd finns
  Postcondition:
  return: antal noder i träd */
int tree_count(Node *root);

/*Precondition:
  Postcondition: Sorterar arrayen enligt trädet (inorder)
  return: */
void traversal(Node *root, int *arr, int *i);

/*Precondition:
  Postcondition: skriver ut data till konsolen rekursivt
  return: */
void preorder(Node *root);

/*Precondition:
  Postcondition: skriver ut data till konsolen rekursivt
  return: */
void inorder(Node *root);

/*Precondition:
  Postcondition: skriver ut data till konsolen rekursivt
  return: */
void postorder(Node *root);

/*Precondition: Listan är inte tom
  Postcondition: Listan och noder frigörs
  return: */
void destroy(Node *node);

// Test funktioner (används ej)
/*Precondition: noden representerar inte det tomma trädet och har inte ett barn
  Postcondition: den nya noden är barn till den noden
  Return:*/
void insertLeftOrRight(Node *node, Node *newNode);
/*Precondition:
  Postcondition: byter plats på två värden
  return: */
void swap(int *xp, int *yp);
/*Precondition:
  Postcondition: sorterar arrayen
  return: */
void bubble_sort(int arr[], int n);



#endif // NODE_H_INCLUDED
