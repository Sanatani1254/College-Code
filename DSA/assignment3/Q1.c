//Q12 find duplicates
#include <stdio.h>

int main()
{   
    int arr[6] = {8,6,3,8,-1,-70};
    int size = 6;

    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j]) 
            {
                printf("%d\n",arr[i]);
                break; 
            }
        }
    }
    return 0;
}