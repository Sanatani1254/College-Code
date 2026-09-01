#include <stdio.h>
#include <stdlib.h>
//singly circular
struct Node
{
    int val;
    struct Node *next;
};

void printlist(struct Node *ptr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ,", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(struct Node **start, int *n, int k)
{
    struct Node *ptr = *start, *temp;
    k %= *n;
    if (*n == 0) 
    {
        (*start)->val = -1;
        (*start)->next = NULL;
        *n = 1;
        return;
    }

    if (k == 0) 
    { // insert before head
        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->val = -1;
        temp->next = *start;

        ptr = *start;
        for (int i = 0; i < *n - 1; i++) 
            ptr = ptr->next;
        ptr->next = temp;

        *start = temp;
        (*n)++;
        printf("Inserted\n");
        printlist(*start, *n);

    } else { //insert in between
        ptr = *start;
        for (int i = 0; i < k - 1; i++)
            ptr = ptr->next;

        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->val = -1;
        temp->next = ptr->next;
        ptr->next = temp;
        (*n)++;
        printf("Inserted\n");
        printlist(*start, *n);
    }
}

void delete(struct Node **start, int *n, int k)
{
    if(*n == 0)
    {
        printf("NOT Possible");
        return;
    }
   struct Node *ptr = *start, *temp;
    k %= (*n);
    if(k == 0)
    {//Delete  head
        temp = *start;
        ptr = *start;

        for(int i = 0;i<*n-1;i++)
        {
            ptr = ptr->next;
        }
        ptr->next = (*start)->next;
        *start = (*start)->next;
        free(temp);
        (*n)--;
        printf("Deleted\n");
        printlist(*start,*n);
    }else
    {//delete in between
        ptr = *start;

        for(int i = 1;i<= k-1;i++)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        (*n)--;
        printf("Deleted\n");
        printlist(*start,*n);
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

    printf("Delete in between\n");
    delete(&start,&n,k);

    printf("Delete at head\n");
    delete(&start,&n,0);
    
}