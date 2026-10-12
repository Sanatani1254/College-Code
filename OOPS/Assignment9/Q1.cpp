#include <iostream>

class book
{
    private:
    std::string name;
    std::string category;
    public:
    book(){name = "NILL";category = "NILL";}//non parametrized
    book(std::string n,std::string c): name(n),category(c) {}//parametrized
    book(book &a)//copy constructor
    {
        name = a.name;
        category = a.category;
    }

    void display()
    {
        std::cout<<"name: "<<name<<"|Category: "<<category<<std::endl;
    }
};

int main()
{
    std::cout<<"NON parametrized constructor b1->"<<std::endl;
    book b1;
    b1.display();
    std::cout<<"parametrized constructor b2->"<<std::endl;
    book b2("Concepts of physics","Exam Preparation");
    b2.display();
    std::cout<<"Copy constructor b3 copies b2"<<std::endl;
    book b3(b1);
    b2.display();

}