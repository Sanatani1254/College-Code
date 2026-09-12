#include <iostream>

class Student {};

int main() 
{
    Student s1;
    Student s2;
    Student s3;

    std::cout<<"Size of empty class:"<<sizeof(Student)<<"bytes"<<std::endl;
    std::cout<<"s1 address:"<<&s1 <<std::endl;
    std::cout<<"s2 Address:"<<&s2<<std::endl;
    std::cout<<"s3 Address:"<<&s3<<std::endl;
}