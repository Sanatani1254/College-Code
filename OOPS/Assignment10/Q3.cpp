#include <iostream>

class animal
{
    public:
    virtual void  sound() = 0;
};

class dog: public animal
{
    public:
    void  sound() override {std::cout<<"bow bow"<<std::endl;}
};

class cat: public animal
{
    public:
    void sound() override {std::cout<<"Meow"<<std::endl;}
};

int main()
{
    dog ogdog;
    cat cat;
    animal* dogyy = &ogdog;
    animal* catuu = &cat;

    dogyy->sound();
    catuu->sound();
}