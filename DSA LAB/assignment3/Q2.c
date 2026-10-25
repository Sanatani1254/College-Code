//Q5 Rain water
#include <stdio.h>

int main()
{
    int arr[6] = {4,2,0,3,2,5};
    int size = 6;
    int left = 0;
    int right = size - 1;
    int leftMax = 0;
    int rightMax = 0;
    int water = 0;

    while (left<right) {
        if (arr[left]<=arr[right]) 
        {
            if (arr[left]>=leftMax) 
            {
                leftMax=arr[left];
            } 
            else 
            {
                water+=leftMax-arr[left];
            }
            left++;
        } 
        else 
        {
            if (arr[right]>=rightMax) 
            {
                rightMax=arr[right];
            } 
            else 
            {
                water+=rightMax-arr[right];
            }
            right--;
        }
    }

    printf("%d\n", water);
    return 0;
}