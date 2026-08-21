#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

class circleradius
{
    private:
    int r;

    public:

    void input()
    {
        std::cout<<"Enter radius:";
        std::cin>>r;
    }

    void display()
    {
        std::cout<<"Radius:"<<r;
    }

    void area()
    {
        std::cout<<"Area:"<<M_PI*r*r<<std::endl;
    }

    void paremeter()
    {
        std::cout<<"paremeter:"<<2*M_PI*r<<std::endl;
    }
};

int main()
{
    circleradius r1;
    r1.input();
    r1.area();
    r1.paremeter();
}