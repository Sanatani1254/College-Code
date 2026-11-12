#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int val;
    struct node *left,*right;
};

struct node* newNode(int val) 
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

struct node *first = NULL, *second = NULL, *prev = NULL;

void find(struct node* root) 
{
    if (root == NULL) return;

    find(root->left);

    if (prev != NULL && prev->val > root->val) 
    {
        if (first == NULL) 
        {
            first = prev;     
            second = root;      
        } 
        else 
        {
            second = root;     
        }
    }
    prev = root;

    find(root->right);
}

void recovertree(struct node* root) 
{
    first = second = prev = NULL;
    find(root);

    if (first && second) 
    {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}

void display(struct node* root) 
{
    if (root == NULL) return;
    display(root->left);
    printf("%d ", root->val);
    display(root->right);
}

void freeTree(struct node* root) 
{
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() 
{

    struct node* root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(8);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(4);
    root->right->right = newNode(9);

    printf("Before: ");
    display(root);
    printf("\n");

    recovertree(root);

    printf("After:  ");
    display(root);
    printf("\n");

    freeTree(root);
    return 0;
}