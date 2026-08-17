#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
    float num = 99.3343;
    cout << ::fixed 
              << ::setw(10) 
              << ::setprecision(2) 
              << ::setfill('*') 
              << num << ::endl;
return 0;
}