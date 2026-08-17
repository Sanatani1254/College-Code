#include<iostream>
#include<string>

struct person
{
    std::string Name;
    int Aadhar;
    std::string Birthdate;
};

int main()
{
    struct person p;
    std::cout<<"Name:";
    std::cin>>p.Name;
    std::cout<<"Aadhar:";
    std::cin>>p.Aadhar;
    std::cout<<"Birthdate:";
    std::cin>>p.Birthdate;

}