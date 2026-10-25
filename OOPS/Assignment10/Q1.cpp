#include <iostream>

class animal
{
    public:
    void sound() {std::cout<<"Grrrr";}
};

class dog: public animal
{
    public:
    void sound() {std::cout<<"bow bow";}
};

int main()
{
    dog ogdog;
    animal *baseclassptr = &ogdog;
    baseclassptr->sound();
}