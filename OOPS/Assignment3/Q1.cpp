#include <iostream>

int power(int n) 
{
    return n*n*n;
}

int power(int n,int p)
{
    int ans = 1;
    for(int i = 0;i<p;i++)
    {
        ans *= n;
    }
    return ans;
}

int main()
{
    std::cout<<power(5)<<std::endl;
    std::cout<<power(5,2)<<std::endl;
}