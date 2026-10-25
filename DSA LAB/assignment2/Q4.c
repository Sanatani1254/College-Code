#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));
    printf("Enter elements:\n");

    for (int i = 0;i<n;i++) scanf("%d",&arr[i]);

    printf("How mach to rotate?\n");
    scanf("%d", &k);
    k = k %n;

    int i =0,j = n -1,temp = 0;
    while (i<j)
    {
        temp = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = temp;
        i++; 
        j--;
    }

    i = 0; j = k - 1;
    while (i<j)
    {
        temp = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = temp;
        i++; 
        j--;
    }

    i = k;j = n - 1;
    while (i<j)
    {
        temp = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = temp;
        i++; 
        j--;
    }
    printf("Rotated array:\n");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}