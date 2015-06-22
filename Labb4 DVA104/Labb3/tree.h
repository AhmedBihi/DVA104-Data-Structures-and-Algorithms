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
  return: returnar ett allokerat tr�d*/
Tree *createTree();

/*Precondition:
  Postcondition: ny nod s�tts in i tr�det
  return: */
void insert(Tree *tree, int data);

/*Precondition: om noden �r null return
  Postcondition: tar bort en nod i ett deltr�d
  return:  */
void tree_remove(Tree *tree, int data);

/*Precondition:
  Postcondition:
  return:  */
void find_tree(Tree *tree);

/*Precondition:
  Postcondition:
  return: teortiska min v�rdet */
int theoretical_min(Tree *tree);

/*Precondition:
  Postcondition:
  return: antalet noder i det bin�ra tr�det */
int tree_size(Tree *tree);

/*Precondition:
  Postcondition:
  return: det bin�ra tr�dets h�jd */
int tree_height(Tree *tree);

/*Precondition: tr�det �r inte tomt
  Postcondition: tr�det balanseras
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

/*Precondition: att det finns ett tr�d
  Postcondition: Frig�r allokerat minne f�r tr�d och skapar ett nytt tr�d
  return:  */
void clear_tree(Tree *tree);

/*Precondition: att det finns ett tr�d
  Postcondition: Frig�r allokerat minne f�r tr�d och noder
  return:  */
void destroyTree(Tree *t);

#endif // TREE_H_INCLUDED
