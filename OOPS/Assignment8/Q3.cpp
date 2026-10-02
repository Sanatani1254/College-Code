#include <iostream>


class Parent 
{
    protected:
        int parentVal;
    public:
        Parent(int p):parentVal(p) 
        {
            std::cout<<"parent has "<<parentVal<<"\n";
        }
};

class Child:public Parent 
{
    private:
        int childVal;
    public:
        Child(int p,int c):Parent(p),childVal(c) 
        {
            std::cout<<"child has "<<childVal<<"\n";
        }
};

int main() 
{
    Child obj(10, 20);
    return 0;
}