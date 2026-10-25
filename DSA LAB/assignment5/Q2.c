#include <stdio.h>
#include <stdlib.h>
//doubly circular
struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
};

void printlist(struct Node *ptr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ,", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(struct Node **start,int *n,int k)
{
    struct Node *ptr = *start, *temp,*ptrP;
    if (*n == 0) 
    {
        (*start)->val = -1;
        (*start)->next = *start;
        (*start)->prev = *start;
        *n = 1;
        return;
    }
    k %= *n;
    if (k == 0) 
    { // insert before head
        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->val = -1;
        temp->next = *start;
        ptr = *start;

        for(int i = 0;i<*n-1;i++)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }else{//insert in between
        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->val = -1;
        ptr = *start;

        for(int i = 0;i<k;i++)
        {   
            ptr = ptr->next;
        }

        ptrP = ptr->prev;
        temp->next = ptr;
        temp->prev = ptrP;
        ptrP->next = temp;
        ptr->prev = temp;
    } 
}

int main()
{
    struct Node *start,*ptr,*temp,*ptr1;
    int n = 11;
    start = (struct Node*) malloc(sizeof(struct Node));
    start->val = 0;
    start->next = NULL;
    ptr = start;

    for(int i = 0;i<n;i++)
    {
        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->val = i+1;
        temp->next = NULL;
        ptr->next = temp;
        ptr = ptr->next;
    }
    ptr->next = start;

    int k = 5;
    printf("Original\n");
    printlist(start,n);

    printf("Insert at head\n");
    insert(&start,&n,0);

    printf("Insert in between\n");
    insert(&start,&n,k);
    
}