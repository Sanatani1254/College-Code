#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5] = {10, 7, 5, 6, 4};
    int n = 5;
    int target = 11;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                printf("%d, %d\n", arr[i], arr[j]);
                return 0;
            }
        }
    }
    printf("\nNo pair found");
    return 0;
}