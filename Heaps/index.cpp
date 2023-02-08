#include <bits/stdc++.h>
using namespace std;
/*
   should be a CBT
   parent of a node => i/2
   childs of a node => (i*2) L|R (i*2+1)
   leaf nodes in a heap array are from : (n/2)+1 to nth element

 */

class heap
{
public:
    vector<int> hp = {-1};

    void insert(int n) // 0(log n)
    {
        hp.push_back(n); // push new elem to the last
        int index = hp.size() - 1;
        int parent;
 
        // heapify up
        while (index > 1) // building the heap
        {
            parent = index / 2;
            if (hp[parent] < hp[index]) // if child>Parent => swap and child=parent
            {
                swap(hp[parent], hp[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void del() // 0(log n)
    {

        hp[1] = hp[hp.size() - 1];
        hp.pop_back();
        int i = 1;
        while (i < hp.size())
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = hp[left] > hp[right] ? left : right;

            if (hp[i] < hp[largest])
            {
                swap(hp[largest], hp[i]);
                i = largest;
            }
            else
                return;
        }
    }

    // 0(log n) 0-based Indexing => put only nth elem to its correct place
    void maxHeapify(vector<int> &arr, int n)
    {
        int largest = n;
        //  0 based indexing
        int l = 2 * n + 1; // left = 2*i + 1
        int r = 2 * n + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < arr.size() && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < arr.size() && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != n)
        {
            swap(arr[n], arr[largest]);
            maxHeapify(arr, largest);
        }
    }

    // 0(n) 1-based Indexing (my algo to minheapify whole array => every elem)
    void minHeapify(vector<int> &arr, int n)
    {
        cout << n << ": \n";

        if (n <= 0)
            return;

        int left = 2 * n;
        int right = 2 * n + 1;
        int smallest = n;

        if (left < arr.size() && arr[left] < arr[smallest])
            smallest = left;

        if (right < arr.size() && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != n)
        {
            cout << "swapping " << arr[smallest] << " and " << arr[n] << endl;
            swap(arr[smallest], arr[n]);
            minHeapify(arr, n - 1);
        }
    }

    void print()
    {
        for (int i = 1; i < hp.size(); i++)
            cout << hp[i] << " ";
    }
};

int main()
{

    heap h;
    vector<int> v = {1, 2, 3, 4, 5, 6};
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.del();
    // h.del();
    // h.print();
    for (int i = (v.size() - 1) / 2; i >= 0; i--)
        h.maxHeapify(v, i);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\n\n";
    //   ----------------STL-----------------
    priority_queue<int, vector<int>> pq;
    pq.push(30); // log n
    pq.push(40);
    pq.push(3);
    pq.pop();   // log n
    cout << pq.top(); // 1
    return 0;
}
