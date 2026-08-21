#include<iostream>

class complex
{
    private:

    float rel;
    float im;

    public:
    
    complex()
    {
        float r;
        float i;
        std::cout<<"Enter realpart:";
        std::cin>>r;
        std::cout<<"Enter Imeginarypart:";
        std::cin>>i;
        rel = r;
        im = i;
    }

    void display()
    {
        std::cout<<rel<<"+"<<"i"<<im<<std::endl;
    }

    void add(float rnew,float inew)
    {
        rel +=rnew;
        im += inew;
    }
};

int main()
{
    class complex num;
    num.display();
    std::cout<<"Adding 5+i5"<<std::endl;
    num.add(5,5);
    num.display();
   


}