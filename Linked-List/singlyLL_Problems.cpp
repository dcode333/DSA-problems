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
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}
void insertAtTail2(node *&head, int val, node *inter)
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

void reverseListIT(node *&head)
{
    node *prev = NULL;
    node *current = head;
    node *next = current->next;

    while (current->next != NULL)
    {
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }
    current->next = prev;
    head = current;
}
node *reverseListRec(node *head, node *prev, node *current, node *next)
{
    if (current->next == NULL)
    {
        current->next = prev;
        head = current;
        return head;
    }
    current->next = prev;
    return reverseListRec(head, current, next, next->next);
}
node *reverseListRec2(node *head)
{
    if (head->next == NULL)
        return head;
    node *newH = reverseListRec2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newH;
}
node *reverseKNodes(node *&head, int k)
{

    if (head == NULL)
        return head;

    node *temp = head;
    for (int i = 1; i < k; i++)
    {
        if (temp->next == NULL)
            break;
        temp = temp->next;
    }

    node *last = temp->next;
    temp->next = NULL;

    // store the address of first node of every sub-LL so that when it is
    // reversed this node will be the last and we will assign caller to
    // it's next
    node *lastNodeAddress = head;
    node *caller = reverseKNodes(last, k);
    node *reversed = reverseListRec2(head);

    lastNodeAddress->next = caller;

    return reversed;
}
void intersectionPoint(node *h1, node *h2)
{
    int l1 = lengthLL(h1);
    int l2 = lengthLL(h2);
    node *smaller = l1 > l2 ? h1 : h2;
    node *bigger = l1 < l2 ? h1 : h2;

    if (l1 != l2)
    {
        int difference = abs(l1 - l2);
        for (int i = 0; i < difference; i++)
            smaller = smaller->next;
    }

    while (smaller != bigger)
    {
        smaller = smaller->next;
        bigger = bigger->next;
    }
    cout << "Intersection Point is: " << smaller->data << ":" << bigger->data;
}
node *mergeTwoSortedLLIT(node *h1, node *h2)
{
    // alternative appraoch:
    // make a dummylist
    // traverse both sorted LL and link the node in dummy list which is smaller
    // go forward in the LL with smaller node
    node *smallFirst = (h1->data) < (h2->data) ? h1 : h2;
    node *bigFirst = (h1->data) > (h2->data) ? h1 : h2;
    node *temp;

    while (smallFirst->next != NULL)
    {

        if (bigFirst->data > smallFirst->next->data)
            smallFirst = smallFirst->next;
        else
        {
            temp = bigFirst;
            bigFirst = bigFirst->next;
            temp->next = smallFirst->next;
            smallFirst->next = temp;
        }
    }

    if (bigFirst->next != NULL)
        smallFirst->next = bigFirst;

    return (h1->data) < (h2->data) ? h1 : h2;
}
node *mergeTwoSortedLLRec(node *h1, node *h2)
{
    if (h1->next == NULL)
        return h2;
    if (h2->next == NULL)
        return h1;

    node *merged;
    if (h1->data < h2->data)
    {
        merged = h1;
        merged->next = mergeTwoSortedLLRec(h1->next, h2);
    }
    else
    {
        merged = h2;
        merged->next = mergeTwoSortedLLRec(h1, h2->next);
    }

    return merged;
}
node *putOddNodesFirst(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenHead = even;

    while (even->next != NULL && odd->next != NULL)
    {

        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        if (odd->next != NULL)
            even = even->next;
    }

    odd->next = evenHead;
    return head;
}

int main()
{
    node *head = NULL; // It will be changed after every insertAtTail call cuz of referencing in func params

    // MergedLL
    // insertAtTail(head, 5);
    // insertAtTail(head, 6);
    // insertAtTail(head, 7);
    // insertAtTail(head, 8);
    // insertAtTail(head2, 1);
    // insertAtTail(head2, 2);
    // insertAtTail(head2, 3);
    // insertAtTail(head2, 4);
    // insertAtTail(head3, 10);
    // insertAtTail(head3, 11);
    // insertAtTail2(head2, 10, head);
    // insertAtTail2(head3, 11, head);
    // intersectionPoint(head2, head3);

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    node *nh = putOddNodesFirst(head);
    displayList(nh);

    return 0;
}
