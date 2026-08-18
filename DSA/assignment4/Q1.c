#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

void  printlist(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ,",ptr->val);
        ptr = ptr->next;
    }
}
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
     printlist(start);
    printf("\ninsertion\n");

    ptr = start;
    //insertion at head
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->val = -1;
    temp ->next = start;
    start = temp;

    //insertion in between
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
    
     printlist(start);
    printf("\n");
    //deletion
    printf("deletion\n");
    //head deletion
    ptr = start;
    start = start->next;
    free(ptr);
    //deletion in between

    ptr = start;
    for(int i = 1;i<3;i++)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    //deletion at end
    ptr = start;
    while(ptr->next->next!=NULL)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = NULL;
    free(temp);

     printlist(start);

}