#include <iostream>

class complex
{
    private:
    int real;
    int im;

    public:

    void input()
    {
        int r,i;
        std::cout<<"Enter real part:";
        std::cin>>r;
        std::cout<<"Enter imeginary part:";
        std::cin>>i;
        real = r;
        im = i;
    }

    void display()
    {
        if(im<0)
        {
            std::cout<<real<<"-"<<im<<std::endl;
        }else{
            std::cout<<real<<"+"<<im<<std::endl;
        }

    }

    friend complex add(complex &c1,complex &c2);
    friend complex multiply(complex &c1,complex &c2);
};

complex add(complex &c1,complex &c2)
{
    complex temp;
    temp.real = c1.real + c2.real;
    temp.im = c1.im + c2.im;
    return temp;
}

complex multiply(complex &c1,complex &c2)
{
    complex temp;
    temp.real = (c1.real*c2.real) - (c1.im*c2.im);
    temp.im = (c1.real*c2.im) + (c1.im*c2.real);
    return temp;
}

int main()
{
    complex num1,num2;
    std::cout<<"input 1st complex num:"<<std::endl;
    num1.input();

    std::cout<<"input 2nd complex num:"<<std::endl;
    num2.input();

    std::cout<<"Add:";
    add(num1,num2).display();
    std::cout<<"Multiply:";
    multiply(num1,num2).display();
}