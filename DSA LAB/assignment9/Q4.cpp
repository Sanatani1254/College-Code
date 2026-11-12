#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node 
{
    int data;
    struct node *left, *right;
};

struct node* newnode(int val) {
    struct node* n =(struct node*) malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

int best = 0;

int solve(struct node* root, int *min, int *max, int *sum) 
{
    if (!root) 
    {
        *min = INT_MAX;
        *max = INT_MIN;
        *sum = 0;
        return 1;
    }

    int lmn, lmax, lsum, rmin, rmax, rsum;
    int lok = solve(root->left,  &lmn, &lmax, &lsum);
    int rok = solve(root->right, &rmin, &rmax, &rsum);

    if (lok && rok && root->data > lmax && root->data < rmin) {
        *sum = lsum + rsum + root->data;
        *min  = (lmn < root->data) ? lmn : root->data;
        *max  = (rmax > root->data) ? rmax : root->data;
        if (*sum > best) best = *sum;
        return 1;
    }
    return 0;
}

int maxBSTSum(struct node* root) {
    int min, max, sum;
    best = 0;
    solve(root, &min, &max, &sum);
    return best;
}

int main() {
    struct node* root = newnode(5);
    root->left = newnode(4);
    root->right = newnode(8);
    root->left->left = newnode(3);
    root->left->right = newnode(6);
    root->right->left = newnode(7);
    root->right->right = newnode(9);

    printf("Maximum BST subtree sum = %d\n", maxBSTSum(root));
    return 0;
}