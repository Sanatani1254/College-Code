#include <stdio.h>

int main()
{
    int arr[8] = {1, 1, 70, 27, 8, 92, 92, 27};
    int large[2] = {arr[0], arr[0]};
    int small[2] = {arr[0], arr[0]};

    for (int i = 1; i < 8; i++)
    {
        if (arr[i] < small[0])
        {
            small[1] = small[0];
            small[0] = arr[i];
        }
        if ((arr[i] < small[1]||(small[0] ==small[1])&&arr[i] !=small[0]))
            small[1] =arr[i];

        if (arr[i] > large[0])
        {
            large[1] =large[0];
            large[0] =arr[i];
        }
        if (arr[i] >large[1] && arr[i] <large[0])
            large[1] = arr[i];
    }

    printf("2nd greatest element is %d\n", large[1]);
    printf("2nd smallest element is %d\n", small[1]);
}