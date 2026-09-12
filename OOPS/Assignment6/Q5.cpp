#include <iostream>

class Distance 
{
private:
    int feet;
    int inches;

public:
    Distance(int f = 0,int i = 0) : feet(f),inches(i) {}
    void display() 
    {
        std::cout<<feet<<"feet"<<inches<<"inches"<<std::endl;
    }
    friend class Calculator;
};

class Calculator {
public:
    Distance add(const Distance& d1, const Distance& d2) {
        Distance temp;
        temp.inches = d1.inches + d2.inches;
        temp.feet = d1.feet + d2.feet + (temp.inches/12);
        temp.inches %= 12;
        
        return temp;
    }
};

int main() {
    Distance d1(5, 9);
    Distance d2(3, 6);
    
    std::cout<<"d1 = ";
    d1.display();

    std::cout<<"d2 = ";
    d2.display();

    Calculator calc;
    Distance d3 = calc.add(d1, d2);
    std::cout<<"d3 = d1 + d2"<<std::endl;
    std::cout<<"d3 = ";
    d3.display();

    return 0;
}