#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node* next;
    Node* prev;
};

void InsertAtBeginning(Node*& head, int value)
{
    /*
        1-Create a new node with the desired value.
        2-Set the next pointer of the new node to the current head of the list.
        3-Set the previous pointer of the current head to the new node.
        4-Set the new node as the new head of the list.
    */

    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

Node* Find(Node* head, int Value)
{

    while (head != NULL)
    {

        if (head->value == Value)
            return head;


        head = head->next;
    }

    return NULL;


}

void PrintNodeDetails(Node* head)
{

    if (head->prev != NULL)
        cout << head->prev->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << "\n";
    else
        cout << "NULL";

}

// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->next;
    }
}

// Print the linked list
void PrintList(Node* head)
{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";

}

void InsertAfter(Node* current,int Value)
{
    Node* New_node = new Node();
    New_node->value = Value;

    New_node->next = current->next;
    New_node->prev = current;

    if (current->next != NULL)
    {
        current->next->prev = New_node;
    }

    current->next = New_node;

}

void InsertAtEnd(Node* head, int Value)
{
    Node* New_node = new Node();
    New_node->value = Value;
    New_node->next = NULL;

    if (head == NULL)
    {
        New_node->prev = NULL;
        head = New_node;
    }
    else
    {
        Node* Current = head;

        while (Current->next != NULL)
        {
            Current = Current->next;
        }

        Current->next = New_node;
        New_node->prev = Current;
    }
}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(head);
    PrintListDetails(head);


    Node* N1 = Find(head, 2);

    InsertAtEnd(head, 500);


    cout << "\n\n\nLinked List Contenet after InsertAfter:\n";
    PrintList(head);
    PrintListDetails(head);

    return 0;
}