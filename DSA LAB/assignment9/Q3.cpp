#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) 
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val) 
{
    if (!root) return newNode(val);
    if (val<root->data) 
    {
        root->left = insert(root->left, val);
    }
    else 
    {
        root->right = insert(root->right, val);
    }
    return root;
}

int height(struct Node* root) 
{
    if (!root) return 0;
    int l = height(root->left); 
    int r = height(root->right);
    return 1 + (l>r?l:r);
}

void kClosest(struct Node* root, int x, int k) 
{
    int h = height(root);
    struct Node **pred = (struct Node**)malloc((h + 1) * sizeof(struct Node*));  
    struct Node **succ = (struct Node**)malloc((h + 1) * sizeof(struct Node*));  
    int pt = 0, st = 0;

    struct Node* cur = root;
    while (cur) 
    {
        if (cur->data <= x) 
        { 
            pred[pt++] = cur; 
            cur = cur->right; 
        }
        else
        { 
            succ[st++] = cur; 
            cur = cur->left;  
        }
    }

    for (int i = 0; i < k && (pt > 0 || st > 0); i++) 
    {
       
        if (pt > 0 && (st == 0 || x - pred[pt-1]->data <= succ[st-1]->data - x)) 
        {
            struct Node* node = pred[--pt];
            printf("%d ", node->data);
            for (struct Node* p = node->left; p; p = p->right)   
                pred[pt++] = p;
        } 
        else 
        {
            struct Node* node = succ[--st];
            printf("%d ", node->data);
            for (struct Node* p = node->right; p; p = p->left)   
                succ[st++] = p;
        }
    }
    printf("\n");
    free(pred);
    free(succ);
}

int main() {
    int a[] = {10, 5, 15, 2, 7, 12, 20, 6, 8};
    struct Node* root = NULL;
    for (int i = 0; i < 9; i++) root = insert(root, a[i]);

    kClosest(root, 9, 4);    
    kClosest(root, 0, 3);    
    kClosest(root, 100, 3);  
    return 0;
}