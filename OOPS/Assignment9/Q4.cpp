#include <iostream>

class person 
{
    public:
    std::string name;
    person(std::string n) : name(n) {}
    void display() 
    {
        std::cout<<"Name:"<<name<<std::endl;
    }
};

class student : public person 
{
    public:
    student(std::string name): person(name) {}
};

class emp : public person 
{
    public:
    emp(std::string name): person(name) {}
};

class asst: public student,public emp 
{
    public:
    asst(std::string sname,std::string ename): student(sname), emp(ename) {}
};

int main() 
{
    asst a("Suryansh","Vinit");
    a.student::display();
    a.emp::display();
}   