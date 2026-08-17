#include<iostream>

int main()
{
    int arr[5][5] = {
                     {1,2,3,4,5},
                     {6,7,8,9,10},
                     {11,12,13,14,15},
                     {1,2,3,4,6},
                     {6,7,8,9,11}
                    };
    int arr1[5][5] = {
                     {1,2,3,4,5},
                     {6,7,8,9,10},
                     {11,12,13,14,15},
                     {1,2,3,4,6},
                     {6,7,8,9,11}
                    };
    int result[5][5];
    int size = 5;
    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<size;j++)
        {
            result[i][j] = arr[i][j] + arr1[i][j];
        }
    }

    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<size;j++)
        {
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}