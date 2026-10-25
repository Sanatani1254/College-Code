#include <stdio.h>
#include <stdbool.h>

int main()
{
    int arr[5] = {-2, 4, -20, 7, -9};
    int n = 5;
    int rearranged[5];
    bool positive = false;

    bool used[5] = {false};
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (positive == false && arr[i] >= 0 && !used[i])
        {
            rearranged[k] = arr[i];
            used[i] = true;
            positive = true;
        }
        else if (positive == true && arr[i] < 0 && !used[i])
        {
            rearranged[k] = arr[i];
            used[i] = true;
            positive = false;
        }
        else
        {
            bool found = false;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] >= 0 && positive == false && !used[j])
                {
                    rearranged[k] = arr[j];
                    used[j] = true;
                    positive = true;
                    found = true;
                    break;
                }
                else if (arr[j] < 0 && positive == true && !used[j])
                {
                    rearranged[k] = arr[j];
                    used[j] = true;
                    positive = false;
                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                for (int j = 0; j < n; j++)
                {
                    if (used[j] == false)
                    {
                        rearranged[k] = arr[j];
                        used[j] = true;
                        break;
                    }
                }
            }
        }
        k++;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", rearranged[i]);
    }

    return 0;
}