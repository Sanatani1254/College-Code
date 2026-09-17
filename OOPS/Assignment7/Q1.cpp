#include <iostream>
#include <string>

class Student 
{
private:
    int roll;
    std::string name;
    std::string course;
    float count1, count2, count3;

public:
friend std::istream& operator>>(std::istream& in, Student& s);
friend std::ostream& operator<<(std::ostream& out, const Student& s);
};
    std::istream& operator>>(std::istream& in, Student& s) 
    {
        std::cout << "Enter Roll Number: ";
        in >> s.roll;

        std::cout << "Enter Name: ";
        in >> std::ws; 
        std::getline(in, s.name);

        std::cout << "Enter Course Title: ";
        std::getline(in, s.course);
        
        std::cout << "Enter marks for count1: ";
        in >> s.count1;
        
        std::cout << "Enter marks for count2: ";
        in >> s.count2;
        
        std::cout << "Enter marks for count3: ";
        in >> s.count3;
        
        return in;
    }

    std::ostream& operator<<(std::ostream& out, const Student& s) {
        float totalMarks = s.count1 + s.count2 + s.count3;
        
        out<<"Roll Number : "<<s.roll<<std::endl;
        out<<"Name: "<<s.name<<std::endl;
        out<<"Course Title: "<<s.course<<std::endl;
        out<<"Total Marks: "<<totalMarks<<std::endl;
        
        return out;
    }


int main() 
{
    Student s1;
    std::cout << "Please enter student details \n";
    std::cin >> s1; 
    std::cout << s1; 
    
    return 0;
}