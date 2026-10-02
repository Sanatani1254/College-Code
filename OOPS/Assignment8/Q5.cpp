#include <iostream>

class Base1 
{
    protected:
        int b1Value;
    public:
        Base1(int b1):b1Value(b1) 
        {
            std::cout<<"basefunc1 used "<<b1Value<<"\n";
        }
};

class Base2 
{
    protected:
        int b2Value;
    public:
        Base2(int b2):b2Value(b2) 
        {
            std::cout<<"base2 basefunc used "<<b2Value<<"\n";
        }
};

class Child : public Base1, public Base2 
{
    private:
        int cValue;
    public:
        Child(int b1,int b2,int c):Base1(b1),Base2(b2),cValue(c) 
        {
            std::cout<<"childfunc used "<<cValue<<"\n";
        }
};

int main() 
{
    Child obj(5,10,15);
    return 0;
}