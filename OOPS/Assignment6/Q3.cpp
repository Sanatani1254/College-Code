#include <iostream>

class Time 
{
private:
    int hr;
    int min;
    int sec;

public:
    Time(int h = 0, int m = 0, int s = 0) : hr(h), min(m), sec(s) {}

    Time operator+(Time t) 
    {
        Time temp;
        temp.sec = sec + t.sec;
        temp.min = min + t.min + temp.sec / 60;
        temp.sec %= 60;
        
        temp.hr = hr + t.hr + temp.min / 60;
        temp.min %= 60;
        
        return temp;
    }

    void display() 
    {
        std::cout<<hr<<":"<<min<<":"<<sec<<std::endl;
    }
};

int main() 
{
    Time t1(3,59,50);
    Time t2(2,30,20);
    
    std::cout << "t1 = ";
    t1.display();
    std::cout << "t2 = ";
    t2.display();

    std::cout << "t3 = t1 + t2" << std::endl;
    Time t3 = t1 + t2; 
    std::cout << "t3 = ";
    t3.display();

}