#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node* next;
};

// Insert at the end
void InsertAtEnd(Node*& head, int Value) {

    Node* new_node = new Node();

    new_node->value = Value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node* LastNode = head;
    while (LastNode->next != NULL)
    {
        LastNode = LastNode->next;
    }

    LastNode->next = new_node;
    return;
}

void DeleteNode(Node*& Head, int Value)
{

    Node* Current = Head, * prev = Head;

    if (Head == NULL)
    {
        return;
    }


    if (Current->value == Value)
    {
        Head = Current->next;
        delete Current;
        return;
    }


    while (Current != NULL && Current->value != Value)
    {
        prev = Current;
        Current = Current->next;
    }

    if (Current == NULL)
    {
        return;
    }

    prev->next = Current->next;
    delete Current;

}

// Print the linked list
void PrintList(Node* head)
{
    cout << "\n";
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    InsertAtEnd(head, 6);
    PrintList(head);

    DeleteNode(head, 4);
    PrintList(head);

	return 0;
}