#include <stdio.h>
#include <stdlib.h>
//reversal of Linked list
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

void reverselist(struct Node **start,int n)
{
  if(n<0)
  {
    printf("Enter a positive n");
    return;
  }
  
  struct Node *ptrP = NULL, *ptrN = NULL, *ptr = *start;
  while (ptr != NULL) {
    ptrN = ptr->next;
    ptr->next = ptrP;
    ptrP = ptr;
    ptr = ptrN;
  }

  *start = ptrP;
}

int main()
{
  struct Node *start,*ptr,*temp,*ptr1;
  int n = 11;
  start = (struct Node*) malloc(sizeof(struct Node));
  start->val = 0;
  start->next = NULL;
  ptr = start;

  for(int i = 0;i<n-1;i++)
  {
      temp = (struct Node*) malloc(sizeof(struct Node));
      temp->val = i+1;
      temp->next = NULL;
      ptr->next = temp;
      ptr = ptr->next;
    }

  printf("ORIGINAL\n");
  printlist(start,n);
  //reversal

  reverselist(&start,n);
  printf("Reversed\n");
  printlist(start,n);
  
}