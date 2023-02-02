#include <bits/stdc++.h>
using namespace std;
/*Algo
min pages can be assigned: 1st page
max pages can be assigned: sum of all pages
=>To compute min of max pages assigned
Take avg of min and max and keep on assigning pages to student
  if(pages exceeds avg without assigning to all students)
   again allocate pages from avg+1 to max to entertain all students
  if(pages are allocated to all students without exceeding avg)
   again allocate pages from min to avg-1 to minimize the max
 */
void binarySearch(int arr[], int key, int low, int high)
{
    if (low >= high)
        return;

    int middle = (low + high) / 2;
    cout << arr[middle] << endl;
    if (arr[middle] > key)
        binarySearch(arr, key, low, middle - 1);
    else if (arr[middle] < key)
        binarySearch(arr, key, middle + 1, high);
    else
    {
        cout << "Found :" << arr[middle];
        return;
    }
}

void pageAllocation(vector<int> arr, int low, int high, int students)
{
    if (low > high)
    {
        cout << low << endl;
        return;
    }

    int middle = (low + high) / 2;
    int sum = 0;
    int student = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((sum + arr[i]) > middle)
        {
            if (student < students)
            {
                student++;
                sum = 0;
                i--;
                continue;
            }
            else
            {
                pageAllocation(arr, middle + 1, high, students);
                return;
            }
        }
        sum += arr[i];
    }

    pageAllocation(arr, low, middle - 1, students);
}

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    pageAllocation(arr, 12, 203, 2);
    return 0;
}
