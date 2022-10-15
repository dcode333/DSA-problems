
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int l[n1], m[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        m[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while (i < n1 && j < n2)
    {
        if (l[i] < m[j])
        {
            arr[k] = l[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = m[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = l[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = m[j];
        k++;
        j++;
    }
}
void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main()
{
    int n = 19;
    int a[n] = {1, 2, 1, 9, 2, 1, 2, 5, 5, 5};
    int uniq;
    int count = 1;

    // could be done using XOR with nearly 0(n^2)

    mergesort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1] && count == 0)
            uniq = a[i];
        else if (a[i] != a[i + 1] && count > 0)
            count = 0;
        else
            count++;
    }

    cout << uniq;

    return 0;
}
