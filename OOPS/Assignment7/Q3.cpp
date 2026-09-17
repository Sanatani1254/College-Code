#include <iostream>

class Time 
{
private:
    int hr;
    int min;

public:
    Time(int h = 0, int m = 0) 
    {
        hr = h;
        min = m;
    }

    operator int() const 
    {
        return (hr*60) + min;
    }

    void display() const 
    {
        std::cout << hr << " hr and " << min << " min";
    }
};

int main() 
{
    int h,m;
    
    std::cout<<"Enter hr elapsed since midnight: ";
    std::cin>>h;
    std::cout<<"Enter min elapsed: ";
    std::cin>>m;

    Time t1(h,m);
    int tmin;

    tmin = t1; 

    std::cout<<"\nTime object: ";
    t1.display();
    std::cout<<"\nConverted to total min: "<<tmin<<" min\n";

    return 0;
}