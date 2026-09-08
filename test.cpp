#include <iostream>
inline void myFunction()
{
 static int count = 0;
 std::cout << count++;
}
int main()
{
 myFunction();
 myFunction();
 myFunction();
 return 0;
}