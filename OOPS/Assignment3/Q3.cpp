#include <iostream>

inline int square(int n)
{
    return n*n;
}

int main()
{
    std::cout<<square(5)<<std::endl;
}