#include <iostream>

class list
{
    public:
    int val;
    list *next;
    list *prev;
    
    list(int v = 0,list *n = nullptr,list *p = nullptr): val(v),next(n),prev(p) {}
};


class stack {
private:
    list* top; 

public:
    stack() { top = nullptr; }

    bool isempty() 
    {
        return top == nullptr;
    }

    void push(int v) 
    {
       list* newNode = new list();
        newNode->val = v;
        newNode->next = top;
        top = newNode;
    }

    int pop() 
    {
        if (isempty()) 
        {
            return 0; 
        }

        list* temp = top;
        int popped = temp->val;
        top = top->next;

        delete temp;

        return popped;
    }
};

int main()
{
    std::string paren = ")()())";
    int valid = 0;
    int invalid = 0;
    stack a;
    for(auto i:paren)
    {
        if(i=='(') a.push('(');
        if(i==')')
        {
            bool x = 0;
            x = a.pop();
            if(!x)
            {
                invalid++;
            }
            valid++; 
        }
    }
    
    if(invalid == 0) 
    {
        std::cout<<"valid, there are "<<valid*2 <<" valid parenthesis";
    }
    else
    {
        std::cout<<"Invalid ,there are "<<invalid<<" parenthesis";
    }
}