#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "";
        temp = temp->next;
    }
}
void insertAtHead(Node *head, int data)
{

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    printLL(head);

    return 0;
}