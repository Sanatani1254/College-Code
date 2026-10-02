#include <iostream>

class Grandparent 
{
    protected:
        int gpVal;
    public:
        Grandparent(int gp):gpVal(gp) 
        {
            std::cout<<"Grandparent used "<<gpVal<<"\n";
        }
};

class Parent : public Grandparent 
{
    protected:
        int pValue;
    public:
        Parent(int gp,int p):Grandparent(gp),pValue(p) 
        {
            std::cout<<"Parent uses "<<pValue<<"\n";
        }
};

class Child : public Parent 
{
    private:
        int cValue;
    public:
        Child(int gp,int p,int c):Parent(gp,p),cValue(c) 
        {
            std::cout<<"Child used "<<cValue<<"\n";
        }
};

int main() 
{
    Child obj(100,200,300);
    return 0;
}