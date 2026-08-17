#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
    float num = 99.3343;
    cout << showpoint;          
    cout << fixed;              
    cout << setprecision(2);     
    cout << right;               
    cout << setw(10);            
    cout << setfill('*');        

    cout << num << endl;
    return 0;
}