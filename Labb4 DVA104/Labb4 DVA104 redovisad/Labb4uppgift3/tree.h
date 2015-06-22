#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "node.h"

typedef struct Tree{
    Node *root;
} Tree;

/*Precondition:
  Postcondition:
  return: ett random tal*/
int randomGen();

/*Precondition:
  Postcondition:
  return: returnar ett allokerat träd*/
Tree *createTree();

/*Precondition:
  Postcondition: ny nod sätts in i trädet
  return: */
void insert(Tree *tree, int data);

/*Precondition: om noden är null return
  Postcondition: tar bort en nod i ett delträd
  return:  */
void tree_remove(Tree *tree, int data);

/*Precondition:
  Postcondition:
  return:  */
void find_tree(Tree *tree);

/*Precondition:
  Postcondition:
  return: teortiska min värdet */
int theoretical_min(Tree *tree);

/*Precondition:
  Postcondition:
  return: antalet noder i det binära trädet */
int tree_size(Tree *tree);

/*Precondition:
  Postcondition:
  return: det binära trädets höjd */
int tree_height(Tree *tree);

/*Precondition: trädet är inte tomt
  Postcondition: trädet balanseras
  return: */
void tree_to_arr(Tree *tree);

/*Precondition:
  Postcondition: skriver ut data till konsolen rekursivt
  return: */
void tree_preorder(Tree *tree);

/*Precondition:
  Postcondition: skriver ut data till konsolen rekursivt
  return: */
void tree_inorder(Tree *tree);

/*Precondition:
  Postcondition: skriver ut data till konsolen rekursivt
  return: */
void tree_postorder(Tree *tree);

/*Precondition: att det finns ett träd
  Postcondition: Frigör allokerat minne för träd och skapar ett nytt träd
  return:  */
void clear_tree(Tree *tree);

/*Precondition: att det finns ett träd
  Postcondition: Frigör allokerat minne för träd och noder
  return:  */
void destroyTree(Tree *t);

#endif // TREE_H_INCLUDED
