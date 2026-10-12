#include <iostream>

class Person 
{
    public:
    std::string name;
    void display() 
    {
        std::cout<<"Name:"<<name<<std::endl;
    }
};


class student :virtual public Person {};
class employee :virtual public Person {};
class assistant : public student,public employee {};

int main() 
{
    assistant a;
    a.name = "Suryansh";
    a.display();
}