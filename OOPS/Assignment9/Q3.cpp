#include <iostream>

class teacher 
{
    public:
    void display() 
    {
        std::cout<<"teacher display() called"<<std::endl;
    }
};

class researcher 
{
public:
    void display() 
    {
        std::cout<<"researcher display() called"<<std::endl;
    }
};

class professor: public teacher,public researcher 
{
    public:
    void display() 
    {
        std::cout<<"professor display() called"<<std::endl;
    }
};

int main() 
{
    professor p;
    p.teacher::display();
    p.researcher::display();
    p.display();
}   