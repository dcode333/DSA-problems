#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int l) // for last node
    {
        data = l;
        next = NULL;
    }
};
void insertAtTail(node *&head, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}
void insertAtTail2(node *&head, int data, node *inter)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = inter;
}
void displayList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << "\b \n";
}
void insertAtHead(node *&head, int data)
{
    node *n;
    n->data = data;
    n->next = head;
    head = n;
}
void deleteFromList(node *&head, int data)
{
    // case pending: if node not found

    node *temp = head;
    if (temp->data == data)
    {
        head = head->next;
        return;
    }

    while (temp->next->data != data)
        temp = temp->next;

    temp->next = temp->next->next;
}
int lengthLL(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

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
    // node *head = NULL;
    // node *head2 = NULL;
    // insertAtTail(head, 2);
    // insertAtTail(head, 4);
    // insertAtTail(head, 9);
    // insertAtTail(head2, 5);
    // insertAtTail(head2, 6);

    // node *nh = addTwoNumbers(head2, head);
    // displayList(nh);


    return 0;
}
