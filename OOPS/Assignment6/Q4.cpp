#include <iostream>

class Time 
{
private:
    int hr;
    int min;

public:
    Time(int h = 0, int m = 0) : hr(h), min(m) {}
    void display()  
    {
        std::cout <<hr<<":"<< min <<std::endl;
    }
    friend Time operator+(Time t1,Time t2);
};

Time operator+(Time t1,Time t2) {
    Time temp;
    temp.min = t1.min + t2.min;

    temp.hr = t1.hr + t2.hr + temp.min/60;
    temp.min %= 60;
    
    return temp;
}

int main() {
    Time t1(3, 45);
    Time t2(2, 30);
    
    std::cout << "t1 = ";
    t1.display();

    std::cout << "t2 = ";
    t2.display();

    std::cout << "t3 = t1 + t2" << std::endl;
    Time t3 = t1 + t2; 
    
    std::cout << "t3 = ";
    t3.display();

    return 0;
}