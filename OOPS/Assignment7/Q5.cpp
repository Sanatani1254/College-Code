#include <iostream>

class Rectangle 
{
private:
    int len;
    int wi;

public:
    Rectangle(int l = 0, int w = 0) 
    {
        len = l;
        wi = w;
    }

    void display() 
    {
        std::cout<<"Rectangle Length: "<< len<<",Width: "<<wi<<std::endl;
    }
};

class Square 
{
private:
    int side;

public:
    Square(int s = 0) 
    {
        side = s;
    }

    void display() 
    {
        std::cout << "Square - Side: " << side << "\n";
    }

    operator Rectangle() 
     {
        return Rectangle(side, side);
    }
};

int main() 
{
    Square sq(5);
    
    std::cout << "Before Conversion:\n";
    sq.display();

    Rectangle rect = sq; 

    std::cout << "\nAfter Conversion to Rectangle object:\n";
    rect.display();

    return 0;
}