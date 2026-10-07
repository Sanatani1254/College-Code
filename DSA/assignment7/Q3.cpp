#include <iostream>
#include <string>

class list
{
    public:
    char val;
    int indx;
    list *next;
    list *prev;
    
    list(char v = 0, int i = 0, list *n = nullptr, list *p = nullptr): val(v), indx(i), next(n), prev(p) {}
};

class stack 
{
private:
    list* top; 

public :
    stack() { top = nullptr; }

    bool isempty() 
    {
        return top == nullptr;
    }

    void push(char v) 
    {
       list* newNode = new list();
        newNode->val = v;
        newNode->next = top;
        top = newNode;
    }

    char pop() 
    {
        if (isempty()) 
        {
            return 0; 
        }

        list* temp = top;
        char popped = temp->val;
        top = top->next;

        delete temp;

        return popped;
    }
    
    char peek() 
    {
        if (isempty()) 
        {
            return 0; 
        }
        return top->val;
    }
};

int getPrecedence(char op) 
{
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;

    return -1; 
}

int main() 
{
    std::string infix = "a+b/2*(5+6)"; 
    stack a; 
    std::string postfix = "";

    for(int i = 0;i<infix.size();i++) 
    {
        char c = infix[i];

        if (c == ' ') continue;
        if (std::isalnum(c)) 
        {
            postfix += c;
        } 
        else if (c == '(') 
        {
            a.push('(');
        } 
        else if (c == ')') 
        {
            while (!a.isempty() && a.peek()!='(') 
            {
                postfix += a.peek();
                a.pop();
            }
            if (!a.isempty()) 
            {
                a.pop(); 
            }
        } 
        else 
        {
            while (!a.isempty() && a.peek() !='(') 
            {
                char top = a.peek();
                bool isRightAssoc = 0;
                if(c=='^') isRightAssoc = 1;
                if ((!isRightAssoc && getPrecedence(c) <= getPrecedence(top)) || (isRightAssoc && getPrecedence(c) < getPrecedence(top))) 
                {
                    postfix += top;
                    a.pop();
                } 
                else break;
            }
            a.push(c);
            }
    }

    while (!a.isempty()) 
    {
        postfix += a.peek();
        a.pop();
    }

    std::cout<<"Infix:"<<infix<<"\nPostfix:"<<postfix<<std::endl;

    return 0;
}