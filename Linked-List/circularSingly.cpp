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
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        n->next = n;
        return;
    }

    node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
}
void displayList(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << temp->data << "-";
    cout << "\b \n";
}
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    head = n;
}
void deleteFromList(node *&head, int val)
{
    // case pending: if node not found
    node *temp = head;
    node *toDelete;
    if (temp->data == val)
    {
        while (temp->next != head)
            temp = temp->next;

        toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
        return;
    }

    while (temp->next->data != val)
        temp = temp->next;

    temp->next = temp->next->next;
}
int lengthLL(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    node *head = NULL; // It will be changed after every insertAtTail call cuz of referencing in func params

    insertAtTail(head, 3);
    insertAtTail(head, 9);
    insertAtTail(head, 5);
    insertAtTail(head, 8);
    insertAtTail(head, 10);
    insertAtTail(head, 12);
    insertAtTail(head, 13);
    insertAtHead(head, 99);
    displayList(head);

    return 0;
}
