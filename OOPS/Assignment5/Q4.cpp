#include <iostream>
#include <string>

class Student 
{
    private:
        std::string name;
        int rollNumber;
        float marks;

    public:
        Student() 
        {
            std::cout << "Enter Name:";
            std::getline(std::cin, this->name);
            
            std::cout << "Enter Roll Number: ";
            std::cin >> this->rollNumber;
            
            std::cout << "Enter Marks: ";
            std::cin >> this->marks;
            
            std::cin.ignore(); 
        }

        Student(std::string name, int rollNumber, float marks) 
        {
            this->name = name;
            this->rollNumber = rollNumber;
            this->marks = marks;
        }

        void showDetails() const 
        {
            std::cout<<"Name: " << name<<std::endl; 
            std::cout<<"Roll No: "<<rollNumber<<std::endl; 
            std::cout<<"Marks:"<<marks<<std::endl;
        }
};

int main() 
{
    Student student1; 
    Student student2("Ramu", 101, 95.5);
    
    student1.showDetails();
    student2.showDetails();

    return 0;
}