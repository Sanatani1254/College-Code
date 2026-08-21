#include <iostream>

int reverse(int n,int rev)
{
    if(n == 0) return rev;

    int temp = rev * 10 + n%10;
    return reverse(n/10,temp); 
}

int main()
{
    int n,rev = 0;
    std::cout<<"Enter number:";
    std::cin>>n;
    std::cout<<"reversed:"<<reverse(n,rev)<<std::endl;
}