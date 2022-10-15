#include <bits/stdc++.h>
using namespace std;

int firstOcc(int a[], int key, int i, int size)
{
    if (a[0] == key)
        return i;

    if (i == size)
        return -1;

    return firstOcc(a + 1, key, i + 1, size);
}

int lastOcc(int a[], int key, int i, int size)
{

    if (i == size)
        return -1;

    int found = lastOcc(a, key, i + 1, size);
    if (found != -1)
        return found;

    if (a[i] == key)
        return i;

    return -1;
}

int main()
{
    int n = 6;
    int a[n] = {4, 3, 5, 10, 4, 3};

    cout << lastOcc(a, 4, 0, n);
    //  cout << lastOcc(a, 4, n);

    return 0;
}
