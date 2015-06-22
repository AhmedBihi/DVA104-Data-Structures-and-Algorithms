#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "node.h"

Tree *createTree()
{
    Tree *newTree = (Tree *)calloc(1, sizeof(Tree));
    if(newTree == NULL)
        return NULL;
    return newTree;
}

void insert(Tree *tree, int data)
{
    Node *node = createNode(data);
    tree->root = insertSorted(tree->root, node);
}

void tree_remove(Tree *tree, int data)
{
    if(tree->root == NULL) return;
    tree->root = removeNode(tree->root, data);
}

void find_tree(Tree *tree)
{
    Node *tmp;
    int data;
    tmp = NULL;
    printf("Find: ");
    scanf("%d", &data);
    tmp = find(tree->root, data);
    if(tmp)
        printf("Searched node = %d\n", tmp->data);
    else
        printf("Node is not found\n");
}

int theoretical_min(Tree *tree)
{
    return ceil(log(tree_count(tree->root) + 1) / log(2));
}

int tree_size(Tree *tree)
{
    return tree_count(tree->root);
}

int tree_height(Tree *tree)
{
    int height = 0;
    if(tree->root)
        height = max_height(tree->root);
    return height;
}

void tree_to_arr(Tree *tree)
{
    if(tree == NULL) return;

    int size = tree_count(tree->root);
    int end = size - 1;
    int i = 0;
    int *array = malloc(size * sizeof(int));

    traversal(tree->root, array, &i);
    clear_tree(tree);

    tree->root = arr_to_tree(array, 0, end);

    free(array);
    array = NULL;
}

void tree_preorder(Tree *tree)
{
    preorder(tree->root);
}

void tree_inorder(Tree *tree)
{
    inorder(tree->root);
}

void tree_postorder(Tree *tree)
{
    postorder(tree->root);
}

void clear_tree(Tree *tree)
{
    traverse_postorder(tree->root, &free);
    tree->root = NULL;
}

void destroyTree(Tree *t)
{
    Node *doom = t->root;
    destroy(doom);
}


/* Test funktioner
void clearTree(Tree **tree)
{
    destroyTree(*tree);
    *tree = NULL;
    *tree = createTree();
}
void standard_insert(Node **tree, int data)
{
    Node *temp = NULL;
    if(!(*tree)){
        temp = createNode(data);
        *tree = temp;
        return;
    }

    if(data < (*tree)->data){
        standard_insert(&(*tree)->left, data);
    }else{
        standard_insert(&(*tree)->right, data);
    }
}
int iterativFind(Tree *tree, int data)
{
    Node *iterator = tree->root;

    while(iterator != NULL)
    {
        if(data == iterator->data)
            return  1;
        if(data < iterator->data)
            iterator = iterator->left;
        else
            iterator = iterator->right;
    }
    return 0;
}*/
