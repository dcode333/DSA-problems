#include <bits/stdc++.h>
using namespace std;
// Failing test cases
// Intution:
// if middle is not peak than peak will be found
// on elment bigger than middle because then:
//            1) whenever there is a smaller element, then prev will become peak automatically
//            2) if no smaller comes then last will be the peak

int peakElem(vector<int> v, int low, int high)
{

    int middle = (low + high) / 2;
    if ((middle == 0 && v[middle] > v[middle + 1]) || (middle == v.size() - 1 && v[middle] > v[middle - 1]))
        return middle;
    else if (v[middle] > v[middle - 1] && v[middle] > v[middle + 1])
        return middle;
    else if (v[middle + 1] > v[middle])
        return peakElem(v, middle + 1, high);
    else
        return peakElem(v, low, middle - 1);
}

int main()
{
    vector<int> arr = {1};
    cout << "Peak on Index ==> " << peakElem(arr, 0, arr.size() - 1);

    return 0;
}
