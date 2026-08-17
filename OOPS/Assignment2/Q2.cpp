#include<iostream>

int main()
{
    int arrA[5][5] = {
                     {1,2,3,4,5},
                     {6,7,8,9,10},
                     {11,12,13,14,15},
                     {1,2,3,4,6},
                     {6,7,8,9,11}
                    };
    int arrB[5][5] = {
                     {1,2,3,4,5},
                     {6,7,8,9,10},
                     {11,12,13,14,15},
                     {1,2,3,4,6},
                     {6,7,8,9,11}
                    };
    int rowA = 5;
    int colA = 5;
    int colB = 5;

    int result[5][5] = {0};

    for(int i = 0;i<rowA;i++)
    {
        for(int j = 0;j<colB;j++)
        {
            for (int k = 0;k<colA;k++)
            {
                result[i][j] += arrA[i][k]*arrB[k][j]; 
            }
        }
    }

    for(int i = 0;i<rowA;i++)
    {
        for(int j = 0;j<colB;j++)
        {
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}