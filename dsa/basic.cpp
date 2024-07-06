#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *Next;

    Node()
    {
        this->data = 0;
        this->Next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->Next = NULL;
    }
};
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->Next;
        // temp = head;
    }
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    { // empty ll
        // create a node
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    { // Non ll
        Node *newNode = new Node(data);
        newNode->Next = head;
        head = newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->Next = newNode;
        tail = newNode;
    }
}
int findlen(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->Next;
        len++;
    }
    return len;
}
void insertAtPosition(int position, Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int len = findlen(head);
    if (position == len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // step1: find the position: prev & curr
    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->Next;
        i++;
    }
    Node *curr = prev->Next;

    // step2:
    Node *newNode = new Node(data);
    newNode->Next = curr;
    prev->Next = newNode;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    // insertAtTail(head, tail, 40);
    printLL(head);
    insertAtPosition(4, head, tail, 200);
    cout << endl;
    printLL(head);
    return 0;
}