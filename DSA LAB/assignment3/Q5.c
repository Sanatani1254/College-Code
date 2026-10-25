//Q4 Equilibrium array
#include <stdio.h>

int main()
{
    int arr[7] = {1,7,3,6,0,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sumleft = 0;
    int sumright = 0;

    for(int i = 0;i<size;i++)
    {
        sumright += arr[i];
    }

    for(int i = 0;i<size;i++)
    {
        sumright -= arr[i];
        if(sumleft == sumright) 
        {
            printf("at %d\n",i);
            break;
        }
        sumleft += arr[i];
        
    }

    return 0;
}