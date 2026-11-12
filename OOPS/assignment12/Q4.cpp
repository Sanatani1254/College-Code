
#include <iostream>

template <class t>
class Average
{
    t a,b;

public:

    double calculate()
    {
        return (a + b)/2.0;
    }

    Average(t x,t y)
    {
        a = x;
        b = y;
    }

    

    void display()
    {
        std::cout << "Avg:"<<calculate()<<std::endl;
    }
};

int main()
{
    Average<int> a(10, 21);
    Average<int> b(5,8);

    a.display();
    b.display();

}
