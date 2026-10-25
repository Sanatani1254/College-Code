#include <iostream>

template <typename t>
t smallest(t arr[],int s)
{
    t min = arr[0];
    for(int i = 0;i<s;i++)
    {
        if(arr[i]<min) min = arr[i];
    }

    return min;
}

int main()
{
    int arr[] = {5,4,77,88,45,65};
    std::cout<<"Smallest element = "<<smallest(arr,6)<<std::endl;
}