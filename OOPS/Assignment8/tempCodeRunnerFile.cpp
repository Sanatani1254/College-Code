#include <iostream>
#include <string.h>

class student
{protected:
    std::string Name;
    int roll;

    public:
    student(std::string n,int r): Name(n),roll(r)
    {
        std::cout<<"Student constructor"<<std::endl;
    }
};

class marks: public student
{
    protected:
    float theorymarks,practicalmarks;

    public:
    marks(std::string n,int r,float t,float p ): student(n,r),theorymarks(t),practicalmarks(p)
    {std::cout<<"Marks constructor"<<std::endl;}
};

class result : public marks
{
    protected:
    float total;
    float percentage;
    char grade;
    bool status;
    public:
    result(std::string n,int r,float t,float p): marks(n,r,t,p)
    {   std::cout<<"result constructor"<<std::endl;
        calculate();
     
    };

    void calculate()
    {
        total = theorymarks + practicalmarks;
        percentage = (total/200.0)*100.0;

        if (percentage >= 90) grade = 'S';
        else if (percentage >= 80) grade = 'A';
        else if (percentage >= 70) grade = 'B';
        else if (percentage >= 60) grade = 'C';
        else if (percentage >= 50) grade = 'D';
        else if (percentage >= 40) grade = 'E';
        else grade = 'F';
        status = (percentage >= 40) ? 1 : 0;
    }

    void display()
    {
        std::cout<<Name<<":"<<roll<<":"<<percentage<<"%: Grade "<<grade;
        status == 1? std::cout<<" Pass"<<std::endl:std::cout<<" Fail"<<std::endl;;

    }
};

int main()
{
    result r1("Vinit",25103179,90,89);
    r1.display();

}