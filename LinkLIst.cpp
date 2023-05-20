#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *newNode, *temp;
Node *createNode(int val)
{
    newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insert_beging(Node *&head, int val)
{
    newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}
void delete_beging(Node *&head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void insert_end(Node *&head, int val)
{
    newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void delete_end(Node *&head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    else
    {
        temp = head;
        Node *previous;
        while (temp->next != NULL)
        {
            previous = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
        }
        else
        {
            previous->next = NULL;
        }
        delete temp;
    }
}
void insert_poaition(Node *&head, int val, int position)
{
    newNode = createNode(val);
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;
        for (int i = 0; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void dispaly(Node *&head)
{
    newNode = head;
    while (newNode != NULL)
    {
        cout << newNode->data << " ";
        newNode = newNode->next;
    }
    cout << endl;
}
bool searching(Node *&head, int key)
{
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *head = NULL;
    insert_end(head, 1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);

    dispaly(head);

    if (searching(head, 3))
    {
        cout << "3 is found" << endl;
    }
    else
    {
        cout << "3 is not found" << endl;
    }
    
}