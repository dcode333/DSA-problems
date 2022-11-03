#include <bits/stdc++.h>
using namespace std;

string summer(node *n)
{
    if (n == NULL)
        return "";

    string num = to_string(n->data);
    string s = summer(n->next);
    return s + num;
}
string findSum(string s1, string s2)
{

    if (s1.length() > s2.length())
        swap(s1, s2);

    string str = "";

    int n1 = s1.length(), n2 = s2.length();
    int diff = n2 - n1;

    int carry = 0;

    for (int i = n1 - 1; i >= 0; i--)
    {

        int sum = ((s1[i] - '0') +
                   (s2[i + diff] - '0') +
                   carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n2 - n1 - 1; i >= 0; i--)
    {
        int sum = ((s2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        str.push_back(carry + '0');

    return str;
}
node *addTwoNumbers(node *l1, node *l2)
{

    string n1 = summer(l1);
    string n2 = summer(l2);
    string res = findSum(n1, n2);
    cout << res << endl;

    node *newList = new node(res[0] - '0');
    node *newHead = newList;

    for (int i = 1; i < res.size(); i++)
    {
        node *newNode = new node(res[i] - '0');
        newList->next = newNode;
        newList = newList->next;
    }

    return newHead;
}

int main()
{

    return 0;
}
