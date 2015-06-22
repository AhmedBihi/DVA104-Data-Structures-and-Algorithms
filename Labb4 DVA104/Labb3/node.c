#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *createNode(int data)
{
    Node *newNode = (Node *)calloc(1, sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory for new node could not be allocated");
        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertSorted(Node *subTree, Node *newNode)
{
    if(subTree == NULL)
        subTree = newNode;
    else
    {
        if(newNode->data < subTree->data)
            subTree->left = insertSorted(subTree->left, newNode);
        else
            subTree->right = insertSorted(subTree->right, newNode);
    }
    return subTree;
}

Node *find(Node *node, int n)
{
    if(node == NULL)
        return NULL;
    if(n < node->data)
        return find(node->left, n);
    else if(n > node->data)
        return find(node->right, n);
    else if(node->data == n)
        return node;
}

Node *removeNode(Node *node, int data)
{
    if(node == NULL) return NULL;

    /* Letar efter noden till else satsen körs*/
    if(data < node->data)
        node->left = removeNode(node->left, data);
    else if(data > node->data)
        node->right = removeNode(node->right, data);
    else{ /* data == node->data */
        Node *temp = NULL;

        /* 1 lr 0 barn*/
        if(node->left == NULL){
            temp = node->right;
            free(node);
            return temp;
        } else if(node->right == NULL){
            temp = node->left;
            free(node);
            return temp;
        } else {
            temp->data = smallest(node->right); // Kollar efter minsta i höger delträd
            node->data = temp->data; // Kopierar över data
            node->right = removeNode(node->right, temp->data); // Tar bort den minsta i höger delträd
        }
    }

    return node;
}

Node *arr_to_tree(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    Node *node = NULL;

    if(start > end) return NULL;

    node = createNode(arr[mid]);
    node->left = arr_to_tree(arr, start, mid-1);
    node->right = arr_to_tree(arr, mid+1, end);

    return node;
}

int smallest(Node *node)
{
    if(node->left != NULL)
    {
        return(smallest(node->left));
    }
    else
        return(node->data);
}

void traverse_postorder(Node *node, void (*f)(void*))
{
    if (node == NULL) return;
    traverse_postorder(node->left, f);
    traverse_postorder(node->right, f);
    f(node);
}

int max_height(Node *node)
{
    int height = 1;
    if(node){
        if(node->left || node->right){
            int lh = 0, rh = 0;
            if(node->left)
                lh = max_height(node->left);
            if(node->right)
                rh = max_height(node->right);
            if(lh > rh)
                height = lh + 1;
            else
                height = rh +1;
        }
    }
    return height;
}

int tree_count(Node *root)
{
    int count = 0;
    if(root != NULL){
        count = 1 + tree_count(root->left) + tree_count(root->right);
    }
    return count;
}

void traversal(Node *root, int *arr, int *i)
{
    if(root != NULL){
        traversal(root->left, arr, i);
        arr[*i] = root->data;
        *i = *i + 1;
        traversal(root->right, arr, i);
    }
}

void preorder(Node *root)
{
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void destroy(Node *node)
{
    if(node){
        destroy(node->left);
        destroy(node->right);
        free(node);
    }
}

// Test funktioner (används ej)
void insertLeftOrRight(Node *tree, Node *newNode)
{
    if(tree == NULL)
        tree = newNode;
    if(tree->data < newNode->data)
        tree->left = newNode;
    else
        tree->right = newNode;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubble_sort(int arr[], int n)
{
    int i, j;
    for(i=0; i<n; i++)
        for(j = 0; j < n-i-1; j++) // Last i elements are already in place
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
