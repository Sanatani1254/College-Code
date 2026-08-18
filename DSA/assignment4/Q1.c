#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

int main()
{
    struct Node *start = NULL,*temp = NULL,*ptr = NULL;

    start = (struct Node*) malloc(sizeof(struct Node));
    start-> val = 0;
    start-> next = NULL;
    ptr = start;

    for(int i = 0;i<6;i++)
    {
        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->val = i+1;
        temp->next = NULL;
        ptr->next = temp;
        ptr = ptr->next;
    }
    ptr = start;
    while(ptr!=NULL)//print
    {
        printf("%d ,",ptr->val);
        ptr = ptr->next;
    }
    printf("\n");

    ptr = start;
    //insertion at head
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->val = -1;
    temp ->next = start;
    start = temp;

    //insertion in middle
    for(int i = 1;i<3;i++)
    {
        ptr = ptr->next;
    }

    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->val = -1;
    temp->next = ptr->next;
    ptr->next = temp;

    //insertion at end
    ptr = start;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }

    temp = (struct Node*) malloc(sizeof(struct Node));
    temp ->val = -1;
    temp->next = NULL;
    ptr->next = temp;
    ptr = start;
    while(ptr!=NULL)//print
    {
        printf("%d ,",ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}