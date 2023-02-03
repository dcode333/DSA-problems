#include <bits/stdc++.h>
using namespace std;
// parent of a node => i/2
// childs of a node => L(i*2) R(i*2+1)

class heap
{
public:
    vector<int> hp = {-1};

    void insert(int n) // 0(n)
    {
        hp.push_back(n); // push every new elem to the last
        int index = hp.size() - 1;
        int parent;

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

    void del() //0(lg n)
    {
        hp[1] = hp[hp.size() - 1];
        hp.pop_back();
        int i = 1;
        while (i < hp.size())
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            if (hp[left] && hp[right])
            {
                if (hp[left] > hp[right])
                {
                    swap(hp[i], hp[left]);
                    i = left;
                }
                else
                {

                    swap(hp[i], hp[right]);
                    i = right;
                }
            }
            else if (left && hp[left] > hp[i])
            {
                swap(hp[left], hp[i]);
                i = left;
            }
            else if (right && hp[right] > hp[i])
            {
                swap(hp[right], hp[i]);
                i = right;
            }
            else
                return;
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
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.del();
    h.del();
    h.print();

    return 0;
}
