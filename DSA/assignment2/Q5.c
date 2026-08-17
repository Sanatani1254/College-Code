#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start = clock();
    int a[5] = {1, 2, 4, 6, 3};
    int temp;
    for (int i = 0; i < 4;i++)
    {
        for (int j = 0; j < 4 -i; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    clock_t end = clock();
    for (int i = 0;i<5;i++)
    {
        printf("%d\n",a[i]);
    }
    printf("Time spent: %f\n",(double)(end-start)/CLOCKS_PER_SEC);
}