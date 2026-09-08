#include <iostream>

class B
{
    private:
        int x;

    public:

    B(int x) 
    {
        this->x = x;
    }
    friend int findsum(const class A& objA, const class B& objB);
};

class A
{
    private:
        int y;
    
    public:

    A(int y)
    {
        this->y = y;
    }
    friend int findsum(const class A& objA, const class B& objB);
};

int findsum(const class A& objA, const class B& objB)
{
    return objA.y + objB.x;
}

int main()
{
    class A a(64);
    class B b(55);

    std::cout<<"Sum:"<<findsum(a,b)<<std::endl;
}