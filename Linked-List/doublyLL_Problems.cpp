#include <bits/stdc++.h>
using namespace std;
// (Removal of cycle Algo):
// when both hare and toise are equal:  point hare to the head
// move both one step again
// when next of both is equal then make next of toise to NULL

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int l) // for last node
    {
        data = l;
        next = NULL;
        prev = NULL;
    }
};
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
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
void insertAtHead(node *&head, int val) //  |o|  |o| |o|
{
    node *n = new node(val);
    if (head != NULL)
    {
        n->next = head;
        head->prev = n;
    }
    head = n;
}
void deleteFromList(node *&head, int val)
{
    // case pending: if node not found
    //  |o| |o| |o|
    node *temp = head;
    if (temp->data == val)
    {
        head = head->next;
        head->prev = NULL;
        return;
    }

    while (temp->data != val)
        temp = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
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

node *appendLastKNodes(node *&head, int k)
{

    node *temp = head;
    int len = lengthLL(head);
    if (k >= len) // if k is bigger than list len then there will be no appending
        return head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;

    for (int i = 0; i < k - 1; i++)
        temp = temp->prev;

    temp->prev->next = NULL;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;

    return head;
}
node *appendLastKNodes2(node *head, int k)
{
    node *temp = head;
    node *last;
    node *newHead;
    int l = lengthLL(head);
    int count = 1;
    k = k % l; // if a is bigger than b then (a%b) gives 0 else gives a

    while (temp->next != NULL)
    {
        if (count = l - k + 1)
            newHead = temp;
        if (count = l - k)
            last = temp;

        temp = temp->next;
        count++;
    }
    temp->next = head;
    head->prev = temp;

    newHead->prev = NULL;
    last->next = NULL;

    return newHead;
}

int main()
{
    node *h1 = NULL; // It will be changed after every insertAtTail call cuz of referencing in func params
    node *h2 = NULL;

    displayList(h1);
    node *newh = appendLastKNodes2(h1, 6);
    displayList(newh);

    return 0;
}
