#include <iostream>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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

void binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            std::cout << "Element " << target << " found at index " << mid << '\n';
            return;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    std::cout << "Element " << target << " not found in the array" << '\n';
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSortDescending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int arr[] = {1, 2, 0, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    bubbleSort(arr, n);
    std::cout << "Sorted array (Bubble Sort): ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    int target = 4;
    linearSearch(arr, n, target);

    binarySearch(arr, n, target);

    insertionSort(arr, n);
    std::cout << "Sorted array (Insertion Sort): ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    bubbleSortDescending(arr, n);
    std::cout << "Sorted array (Bubble Sort Descending): ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    selectionSort(arr, n);
    std::cout << "Sorted array (Selection Sort): ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}