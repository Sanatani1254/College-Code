#include <iostream>

class Complex 
{
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex& operator++() 
    {
        ++real;
        ++imag;
        return *this;
    }

    Complex operator++(int) 
    {
        Complex temp = *this;
        real++;
        imag++;
        return temp;
    }

    void display() 
    {
        std::cout<<real<<"+"<<imag<<"i"<<std::endl;
    }
};

int main() 
{
    Complex c1(3.5, 4.2);
    std::cout<<"C1 = ";
    c1.display();

    std::cout<<"c2 = ++c1"<<std::endl;
    Complex c2 = ++c1;
    std::cout<<"c1 = "; 
    c1.display();
    std::cout << "c2 =";
    c2.display();

    std::cout<<"c3 = c1++"<<std::endl;
    Complex c3 = c1++; 
    
    std::cout << "c1 =  ";
    c1.display();
    std::cout << "C3 = ";
    c3.display();

    return 0;
}