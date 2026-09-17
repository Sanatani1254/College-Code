#include <iostream>

class Square 
{
private:
    int side;
public:
    Square(int s = 0) 
    {
        side = s;
    }

    int getSide() const 
    {
        return side;
    }

    void display() const 
    {
        std::cout<<"Side: "<<side<<std::endl;
    }
};

class Rectangle 
{
private:
    int length;
    int width;
public:
    Rectangle(int l = 0,int w = 0) 
    {
        length = l;
        width = w;
    }

    Rectangle(Square& sq) 
    {
        length = sq.getSide(); 
        width = sq.getSide();
    }

    void display() const 
    {
        std::cout<<"Length: "<<length<<",Width: "<<width<<std::endl;
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