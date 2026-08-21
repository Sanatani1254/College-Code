#include <iostream>

int cube(int n = 1)
{
    int ans = 1;
    for(int i = 0;i<3;i++)
    {
        ans *= n;
    }
    return ans;
}

int power(int n = 2,int p = 2)
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
    std::cout<<"Without argument:"<<cube()<<std::endl;
    std::cout<<"With argument:"<<cube(2)<<std::endl;
    std::cout<<"Without argument:"<<power()<<std::endl;
    std::cout<<"With argument:"<<power(2,2)<<std::endl;
}