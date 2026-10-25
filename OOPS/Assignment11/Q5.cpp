#include <iostream>

template <typename T>
T fibo(T n) 
{
    if (n <= 1) 
    {
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}

int main() 
{
    int num1 = 10;
    std::cout<<"Fibonacci of "<<num1<<" is "<<fibo(num1)<<std::endl;
}