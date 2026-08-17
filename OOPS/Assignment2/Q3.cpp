#include<iostream>

void callbyvalue(int v)
{
    v+=10;

}

void callbyaddress(int *v)
{
    *v+=10;
}

void callbyrefrence(int &v)
{
    v+=10;
}

int main()
{
    int v = 0;
    callbyvalue(v);
    std::cout<<"call by value:"<<v<<std::endl;

    callbyaddress(&v);
    std::cout<<"call by address:"<<v<<std::endl;
    v = 0;

    callbyrefrence(v);
    std::cout<<"call by refrence:"<<v<<std::endl;

    return 0;
}
