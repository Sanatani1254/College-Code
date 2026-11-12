#include <iostream>
#include <string>

using namespace std;

struct stack
{
    int val[1024];
    int top;
    stack() {top = -1;}
};

bool isfull(const stack &s)
{
    return s.top == 1023;
}

bool push(stack &s, int v)
{
    if (isfull(s)) return false;
    s.top++;
    s.val[s.top] = v;
    return true;
}


bool isempty(const stack &s)
{
    return s.top == -1;
}

bool pop(stack &s, int &v)
{
    if (isempty(s)) return false;
    v = s.val[s.top];
    s.top--;
    return true;
}

bool evaluate(const string &eq, int &result)
{
    stack s;
    int n = eq.size();
    int i = 0;

    while (i < n)
    {
        char c = eq[i];

        if (c == ' ' || c == '\t')
        {
            i++;
            continue;
        }

        
        bool isNum = (c>='0' && c<='9') || (c =='-' && i+1<n && eq[i+1] >= '0' && eq[i+1] <= '9');

        if (isNum)
        {
            bool negative = false;
            if (c == '-')
            {
                negative = true;
                i++;
            }
            int val = 0;
            while (i<n && eq[i]>='0' && eq[i]<='9')
            {
                val = val*10 + (eq[i]-'0');
                i++;
            }
            if (negative) val = -val;

            if (push(s,val) == false)
            {
                cout << "stack overflow\n";
                return false;
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        {
            int a, b;                       
            if (!pop(s, b) || !pop(s, a))
            {
                cout << "not enough operands for '" << c << "'\n";
                return false;
            }

            int r = 0;
            if (c == '+') r = a + b;
            else if (c == '*') r = a * b;
            else if (c == '-') r = a - b;
            else
            {
                if (b == 0)
                {
                    cout << "Error: division by zero\n";
                    return false;
                }
                if (c == '/') r = a / b;
                else r = a % b;
            }
            push(s, r);
            i++;
        }
        else                                     
        {
            cout<<"invalid characters"<<c<< "\n";
            return false;
        }
    }

    if (!pop(s,result))
    {
        cout<<"empty equation\n";
        return false;
    }
    if (!isempty(s))
    {
        cout<<"Error:Wrong equation\n";
        return false;
    }
    return true;
}

int main()
{
    string line;
    int result;
    bool invalid = 1;
    cout<<"Enter postfix equation:\n";
    while(invalid)
    {
        getline(cin,line);
        if (evaluate(line,result))
        {
            cout << result << "\n";
            invalid = 0;
        }
        else 
        {
            cout<<"invalid"<<endl;
        }
    }
}