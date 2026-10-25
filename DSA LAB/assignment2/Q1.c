#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 5;
    int *arr = malloc(size * sizeof(int));
    arr[0] = -2;
    arr[1] = 4;
    arr[2] = -20;
    arr[3] = 7;
    arr[4] = -9;
    char op;
    printf("Enter the operation you want to perform: I for insert, D for delete: ");
    scanf(" %c", &op);
      switch (op)
    {
    case 'I':
    {
        int indx, el;
        printf("Enter the index where you want to insert the element: ");
        scanf("%d", &indx);
        if (indx > size)
        {
            printf("Out of bounds ERROR");
            break;
        }
        printf("Enter the element you want to insert: ");
        scanf("%d", &el);
        int *temp = realloc(arr, (size + 1) * sizeof(int));
        if (temp != NULL)
        {
            arr = temp;
        }
        else
        {
            break;
        }
        for (int i = size; i > indx; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[indx] = el;
        size++;
        break;
    }
    case 'D':
    {
        int indx;
        printf("Enter the index where you want to delete: ");
        scanf("%d", &indx);
        if (indx < 0 || indx >= size)
        {
            printf("Index entered is more than size of array");
            break;
        }

        for (int i = indx; i < size - 1; i++)
        {
            arr[i] = arr[i+1];
        }

        int *temp = realloc(arr,(size -1)*sizeof(int));
        if (temp!=NULL)
        {
            arr=temp;
        }
        size--;
        break;
    }
    default:
        printf("ERROR");
    }

    for (int i =0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}