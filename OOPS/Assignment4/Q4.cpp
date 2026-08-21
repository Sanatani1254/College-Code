#include <iostream>
#include <string>

class marksheet
{
    private:

    int rollno;
    double s1;
    double s2;
    double s3;

    public:

    std::string name;

    void input()
    {
        std::cout << "Enter Your name: ";
        std::getline(std::cin, name);

        std::cout << "Enter Roll Number: ";
        std::cin >> rollno;
        std::cin.ignore();
        
        std::cout << "Enter marks for 3 subjects (out of 100): \n";
        std::cout << "Subject S1:";
        std::cin >> s1;

        std::cout << "Subject S2:";
        std::cin >> s2;

        std::cout << "Subject S3:";
        std::cin >> s3;
    }
    
    double percent()
    {
        return (double) (s1+s2+s3)/3;
    }
};

int main()
{
    marksheet student1;

    student1.input();
    std::cout<<"Pecentage scored by "<<student1.name<<" is :"<<student1.percent()<<"%"<<std::endl;
}