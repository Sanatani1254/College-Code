#include <iostream>
#include <iomanip>
using namespace std;

class Student 
{
    public:
    char name[30];
    int roll;
    float m, p, d;

    void display() {
        float per = (m+p+d) / 3.0;

        cout << left << setw(15) << name;
        cout << right << setw(8) << roll;
        cout << right << fixed << setprecision(2)<< setw(8) << m << setw(8) << p<< setw(8) << d;
        cout << setfill('*') << setw(10) << per << setfill(' ') << endl;
    }
};

int main() {
    Student s[5] = 
    {
        {"Suryansh ",101,80,90,85},
        {"Ansh",102,75,80,85},
        {"Raj",103,88,92,90},
        {"Netra",104,95,90,94},
        {"Neha",105,70,75,80}
    };

    cout << right << setw(8) << "Roll";
    cout << left << setw(15) << "Name";
    cout << right << setw(8) << "Math"<< setw(8) << "Prog"<< setw(8) << "DS"<< setw(10) << "Percent" << endl;

    for (int i = 0; i < 5; i++)
    {
        s[i].display();
    }

    return 0;
}