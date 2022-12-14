#include <bits/stdc++.h>
using namespace std;
// find a pair in array that equals key,,,

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high)
{

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

int main()
{
    int a[5] = {2, 4, 3, 7, 3};
    int len = sizeof(a) / sizeof(a[0]);
    int key = 5;
    int start = 0;
    int end = len - 1;

    quickSort(a, 0, len - 1);
    //    0(n) + sorting complexity approach
    while (start < end)
    {
        if ((a[start] + a[end]) > key)
            end--;
        else if ((a[start] + a[end]) < key)
            start++;
        else
        {
            cout << start << " and " << end << " makes " << key;
            break;
        }
    }

    if (start >= end)
        cout << "No pair found !!";

    return 0;
}