//Q7 rearranging positive and negative
#include <stdio.h>

int main()
{
    int arr[6] = {8,6,3,8,-1,-70};
    int size = sizeof(arr)/sizeof(arr[0]);
    int pt = 0;

    for(int i = 0;i<size;i++)//finds nearest positive number
    {
        if(arr[i]>0)
        {
            pt = i;
            break;
        }
    }

    for(int i = pt+1;i<size;i++)
    {
        if(arr[i]<0)
        {
            int temp = arr[pt];
            arr[pt] = arr[i];
            arr[i] = temp;
            for(int i = pt;i<size;i++)//finds nearest positive number
                {
                    if(arr[i]>0)
                    {
                        pt = i;
                        break;
                    }
                }

        }
    }
    
    for(int i = 0;i<size;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\n");

    return 0;
}