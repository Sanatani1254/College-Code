#include <iostream>

class calculator 
{
    public:
    int add(int a,int b) 
    {
        return a + b;
    }

    int sub(int a,int b) 
    {
        return a - b;
    }

    int mul(int a,int b) 
    {
        return a * b;
    }
};

int main() 
{
    calculator c;
    int x = 5;
    int y = 5;

    int(calculator::*opptr)(int,int);

    opptr = &calculator::add;
    std::cout<<"x+y = "<<(c.*opptr)(x,y)<<std::endl;
    opptr = &calculator::sub;
    std::cout<<"x-y = "<<(c.*opptr)(x,y)<<std::endl;
    opptr = &calculator::mul;
    std::cout<<"x+y = "<<(c.*opptr)(x,y)<<std::endl;
}