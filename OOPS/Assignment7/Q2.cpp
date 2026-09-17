#include <iostream>

class Time 
{
private:
    int hr;
    int min;

public:
    Time() 
    {
        hr = 0;
        min = 0;
    }

    Time(int tmin) 
    {
        hr = tmin/60;    
        min = tmin%60;  
    }

    void display() const 
    {
        std::cout<<hr<<":"<<min<<std::endl;
    }
};

int main() 
{
    int Mindone;
    Time t1;

    std::cout << "Enter elapsed time in min from midnight: ";
    std::cin >> Mindone;

    t1 = Mindone; 

    std::cout << "\nAfter type conversion:\n";
    t1.display();
}