
#include <iostream>

template <class t1, class t2>
class Sum
{
    t1 a;
    t2 b;

public:
    Sum(t1 x, t2 y)
    {
        a = x;
        b = y;
    }

    void display()
    {
        std::cout<<"Double:"<<a<<std::endl;
        std::cout<<"int:"<<b<<std::endl;
        std::cout<<"a+b:"<<a+b<<std::endl;
    }
};

int main()
{
    Sum<double,int> a(123.456,100);

    a.display();

    return 0;
}
