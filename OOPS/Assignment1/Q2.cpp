#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            std::cout << "found at index" << i << '\n';
            return;
        }
    }
    std::cout << "not found in the array" << '\n';
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    linearSearch(arr, 5, 4);
    return 0;
}