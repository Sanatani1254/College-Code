//Q16 Array comparison
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[15] = {1,2,3,4,4,4,5,5,6,7,7,7,7,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *result = malloc( size * sizeof(int));
    int rsize = 0;


    int count = 1;

    for(int i = 0;i<size-1;i++)
    {
        if(arr[i] == arr[i+1]) 
        {
            count++;
            continue;
        }
        else
        {
            result[rsize] = arr[i];
            result[rsize+1] = count;
            count = 1;
            rsize +=2;
        }

    }

    for(int i = 0;i<rsize;i++)
    {
        printf("%d,",result[i]);
    }
    printf("\n");

    return 0;
}