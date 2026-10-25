#include <iostream>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r);
void mergesort(vector<int> &arr, int l, int r);

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    mergesort(arr, 0, arr.size() - 1);

    for (auto &it : arr)
    {
        cout << it << ' ';
    }
    cout << endl;
}

void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[m + i + 1];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;

    int m = l + (r - l) / 2;

    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);

    merge(arr, l, m, r);
}
