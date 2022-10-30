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

    node(int l) // for last node
    {
        data = l;
        next = NULL;
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
void insertAtHead(node *&head, int val)
{
    node *n;
    n->data = val;
    n->next = head;
    head = n;
}
void deleteFromList(node *&head, int val)
{
    // case pending: if node not found

    node *temp = head;
    if (temp->data == val)
    {
        head = head->next;
        return;
    }

    while (temp->next->data != val)
        temp = temp->next;

    temp->next = temp->next->next;
}

bool detectCycle(node *&head) // o o o o o
{
    node *hare = head;
    node *toise = head;
    while (hare != NULL && hare->next != NULL)
    {
        hare = hare->next->next;
        toise = toise->next;
        if (toise == hare)
            return true;
    }
    return false;
}

int main()
{
    node *head = NULL; // It will be changed after every insertAtTail call cuz of referencing in func params
    // cout << detectCycle(head);
    displayList(head);

    return 0;
}
