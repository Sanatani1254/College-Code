#include <iostream>

template <typename t>
void swap(t &a,t &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}

int main()
{
    int a = 5,b = 7;
    std::cout<<"a = "<<a<<"\nb = "<<b<<std::endl;
    swap(a,b);
    std::cout<<"Swap \na = "<<a<<"\nb = "<<b<<std::endl;
}