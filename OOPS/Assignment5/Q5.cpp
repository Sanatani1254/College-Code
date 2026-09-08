#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;
    public:
    Rectangle()
        {
            length = 10;
            breadth = 5;
            cout << "Default Constructor called" << endl;
        } 
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
        cout << "Parameterized Constructor called" << endl;
    }
    Rectangle(const Rectangle &r)
    {
        length = r.length;
        breadth = r.breadth;
        cout << "Copy Constructor called" << endl;
    }
    void display()
    {
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << length * breadth << endl;
    }
    ~Rectangle()
        {
    cout << "Destructor called" << endl;
        }
};
int main()
{
cout << "Creating r1:" << endl;
    Rectangle r1;

cout << "\nCreating r2:" << endl;
    Rectangle r2(20, 10);

 cout << "\nCreating r3 by copying r2:" << endl;
    Rectangle r3(r2);

cout << "\nDetails of r1:" << endl;
    r1.display();

cout << "\nDetails of r2:" << endl;
    r2.display();

cout << "\nDetails of r3:" << endl;
    r3.display();

cout << "\nEnd of main()" << endl;
return 0;
}