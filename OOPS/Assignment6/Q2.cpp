#include <iostream>

class Complex 
{
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    void display()
    {
        std::cout<<real<<"+"<<imag<<"i"<<std::endl;
    }
    friend Complex& operator++(Complex& x);
    friend Complex operator++(Complex& x, int);
};

Complex& operator++(Complex& x) 
{
    ++(x.real);
    ++(x.imag);
    return x;
}

Complex operator++(Complex& x, int) 
{
    Complex temp = x; 
    x.real++;         
    x.imag++;
    return temp;        
}

int main() 
{
    Complex c1(3.5, 4.2);
    
    std::cout << "c1 = ";
    c1.display();

    std::cout << "c2 = ++c1"<<std::endl;
    Complex c2 = ++c1; 
    std::cout << "c1 = ";
    c1.display();
    std::cout << "c2 =  ";
    c2.display();

    std::cout << "c3 = c1++"<<std::endl;
    Complex c3 = c1++; 
    std::cout << "c1 = ";
    c1.display();
    std::cout << "c3 = ";
    c3.display();

}