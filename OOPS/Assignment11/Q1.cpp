#include <iostream>

template <typename t>
t largest(t a,t b)
{
    return a>b? a:b;
}

template <typename t>
t largest(t a,t b,t c)
{
    t max = a;
    if(b>max) 
    {
        max = b;
    }
    if(c>max)
    {
        max = c;
    }
    return max;
}

template <typename t>
t largest(t arr[],int s)
{
    t max = arr[0];
    for(int i = 0;i<s;i++)
    {
        if(arr[i]>max) max = arr[i];
    }

    return max;
}

int main()
{
    int arr[] = {5,4,6,8,99,45,64};
    std::cout<<largest(5,4)<<std::endl;
    std::cout<<largest(5,4,6)<<std::endl;
    std::cout<<largest(arr,7)<<std::endl;

}

