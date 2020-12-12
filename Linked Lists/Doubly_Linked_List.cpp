#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next; // next node
    Node *prev; // previous node
};

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// INSERTION

// function to insert at Beginning
void insertAtBeginning(Node **ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (*ref == NULL)
    {
        *ref = new_node;
        return;
    }
    new_node->next = (*ref);
    (*ref)->prev = new_node;
    (*ref) = new_node;
}

// function to insert at End
void insertAtEnd(Node **ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    // checking if linked list is empty
    if (*ref == NULL)
    {
        *ref = new_node;
        return;
    }
    Node *last = *ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    return;
}

int main()
{
    Node *head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 6);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 21);
    display(head);
    return 0;
}