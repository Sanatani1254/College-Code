#include <stdio.h>
#include <stdlib.h>
//reversal of circular doublyLinked list
struct Node
{
  int val;
  struct Node *prev;
  struct Node *next;  
};

void printlist(struct Node *ptr,int n)
{
  for(int i = 0;i<n;i++) {
      printf("%d ", ptr->val);
      ptr = ptr->next;
  }
  printf("\n");
}

void reverselist(struct Node **start,int n)
{
    if(n<=0 || *start==NULL)
    {
        printf("Enter positive n");
        return;
    }

    struct Node *ptrP = NULL,*ptrN = NULL,*ptr = *start;;
    for(int i = 0;i<n;i++)
    {
        ptrN = ptr->next;
        ptr->next = ptrP;
        ptr->prev = ptrN;
        ptrP = ptr;
        ptr = ptrN;
    }
    (*start)->next = ptr;      
    ptrP->prev = *start;       
    *start = ptrP;
}

int main()
{
    struct Node *start,*ptrP,*ptr,*ptrN,*temp;
    int n = 5;
    start = (struct Node*) malloc(sizeof(struct Node));
    start->val = 0;
    start->next = NULL;
    start->prev = NULL;
    ptr = start;
    for(int i = 0;i<n-1;i++)
    {
        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->val = i+1;
        temp->next = NULL;
        ptr->next = temp;
        temp->prev = ptr;
        ptr = ptr->next;
    }
    ptr->next = start;
    start->prev = ptr;

    printf("Oringinal\n");
    printlist(start,n);

    //reverse
    printf("Reversed\n");
    reverselist(&start,n);
    printlist(start,n);
}