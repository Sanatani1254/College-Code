#include <iostream>

class Stack {
private:
    int arr[20];
    int top;

public:
    Stack() 
    {
        top = -1;
    }
    void push(int value) {
        if (top >= 20 - 1) {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        arr[++top] = value;
        std::cout << value << "pushed" << std::endl;
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow!" << std::endl;
            return -1;
        }
        return arr[top--];
    }
    bool isEmpty() {
        return top < 0;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        std::cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack s;
    for(int i = 0;i<25;i++)
    {
        s.push((i+1)*10);
    }
    s.display();

    std::cout << s.pop() << " popped" << std::endl;
    std::cout << s.pop() << " popped" << std::endl;

    s.display();
    return 0;
}