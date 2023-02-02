#include <bits/stdc++.h>
using namespace std;
// 192 / 195 testcases passed
// *[3,1]=>1 , [5,1,3]=>5 , [0]=>2
/*
Case 1: if (left side is sorted)
case 2: if (left side is unsorted)
Intutuion:
 A sorted left side means we can check if our key is present in that part
 An unsorted left side means right side is sorted so we can find there
*/

int searchInSortedRotated(vector<int> v, int low, int high, int key)
{
    if (low > high)
        return -1;

    int middle = (low + high) / 2;
    cout << v[middle] << " " << endl;
    if (v[middle] == key)
        return middle;

    if (v[low] < v[middle])
    {
        if (key >= v[low] && key <= v[middle])
            return searchInSortedRotated(v, low, middle - 1, key);
        else
            return searchInSortedRotated(v, middle + 1, high, key);
    }
    else
    {
        if (key >= v[middle] && key <= v[high])
            return searchInSortedRotated(v, middle + 1, high, key);
        else
            return searchInSortedRotated(v, low, middle - 1, key);
    }
}

int main()
{

    vector<int> v = {3, 1};

    cout << "Key index ==> " << searchInSortedRotated(v, 0, v.size() - 1, 1);

    return 0;
}
