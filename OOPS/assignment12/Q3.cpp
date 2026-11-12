
#include <iostream>

template <class T>
class Complex
{
    T real,imag;

public:
    Complex(T r = 0,T i = 0)
    {
        real = r;
        imag = i;
    }

    Complex add(Complex c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex subtract(Complex c)
    {
        return Complex(real - c.real, imag - c.imag);
    }

    void display()
    {
        std::cout << real;

        if (imag >= 0)
            std::cout<<"+"<<imag<< "i";
        else
            std::cout<<"-"<<imag*(-1)<<"i";

        std::cout<<std::endl;
    }
};

int main()
{
    Complex<double> c1(4,5);
    Complex<double> c2(2,3);

    Complex<double> sum = c1.add(c2);
    Complex<double> diff = c1.subtract(c2);

    std::cout << "C1:";
    c1.display();

    std::cout << "C2:";
    c2.display();

    std::cout << "Add:";
    sum.display();

    std::cout << "Minus:";
    diff.display();

}
