
#include <iostream>

template <class t>
class Stack
{
    t arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    t peek()
    {
        if (top == -1)
        {
            std::cout << "Empty" << std::endl;
            return t{};
        }
        else
        {
            return arr[top];
        }
    }

    int push(t value)
    {
        if (top == 99)
        {
            std::cout<<"Full"<<std::endl;
            return 0;
        }
        else
        {
            arr[++top] = value;
            return 1;
        }
    }

    t pop()
    {
        if (top == -1)
        {
            std::cout<<"Empty"<<std::endl;
            return t{};
        }
        else
        {
            return arr[top--];
        }
    }

    void display()
    {
        if (top == -1)
        {
            std::cout << "Stack is empty\n";
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            std::cout<<arr[i]<<" ";
        }

        std::cout << std::endl;
    }
};

int main()
{
    Stack<int> s;
    int x = 0;

    for (int i = 0; i < 5; i++)
    {
        x = s.push(i*10);

        if (x == 0)
            std::cout << "ERROR\n";
    }

    s.display();

    std::cout << "Peek:" << s.peek() << std::endl;

    x = s.pop();
    std::cout << "Popped:" << x << std::endl;

    s.display();

}
