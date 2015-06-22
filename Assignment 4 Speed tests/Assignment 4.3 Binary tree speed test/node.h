#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/*Precondition: minne finns tillg�nglig f�r allokering
  Postcondition: ny nod skapad
  return: */
Node *createNode(int data);

/*Precondition:
  Postcondition: s�tter in nya noden sorterat i tr�det
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
  return: returnerar ett balanserat tr�d*/
Node *arr_to_tree(int arr[], int start, int end);

/*Precondition:
  Postcondition:
  return: Den minsta noden i h�ger deltr�d */
int smallest(Node *node);

/*Precondition:
  Postcondition:
  Return:*/
void traverse_postorder(Node *node, void (*f)(void*));

/*Precondition: Tr�d finns
  Postcondition:
  return: max h�jden p� tr�det */
int max_height(Node *node);

/*Precondition: Tr�d finns
  Postcondition:
  return: antal noder i tr�d */
int tree_count(Node *root);

/*Precondition:
  Postcondition: Sorterar arrayen enligt tr�det (inorder)
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

/*Precondition: Listan �r inte tom
  Postcondition: Listan och noder frig�rs
  return: */
void destroy(Node *node);

// Test funktioner (anv�nds ej)
/*Precondition: noden representerar inte det tomma tr�det och har inte ett barn
  Postcondition: den nya noden �r barn till den noden
  Return:*/
void insertLeftOrRight(Node *node, Node *newNode);
/*Precondition:
  Postcondition: byter plats p� tv� v�rden
  return: */
void swap(int *xp, int *yp);
/*Precondition:
  Postcondition: sorterar arrayen
  return: */
void bubble_sort(int arr[], int n);



#endif // NODE_H_INCLUDED
