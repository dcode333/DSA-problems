#include <bits/stdc++.h>
using namespace std;

void median(vector<double> arr)
{
    priority_queue<double, vector<double>> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    double med = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        double x = arr[i];

        // case1(left side heap has more elements)
        if (maxHeap.size() > minHeap.size())
        {
            if (x < med)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else
                minHeap.push(x);

            med = (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // case2(both heaps are balanced)
        else if (maxHeap.size() == minHeap.size())
        {
            if (x < med)
            {
                maxHeap.push(x);
                med = (double)maxHeap.top();
            }
            else
            {
                minHeap.push(x);
                med = (double)minHeap.top();
            }
        }

        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            }
            else
                maxHeap.push(x);

            med = (maxHeap.top() + minHeap.top()) / 2.0;
        }

        cout << med << endl;
    }
}

int main()
{

    vector<double> arr = {1, 2, 40, 5};

    median(arr);

    return 0;
}
