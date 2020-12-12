// Implementing Circular Linked List
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// number of nodes in linked list
int numberNodes(Node *head)
{
    int count = 0;
    Node *current = head;
    if (head == NULL)
    {
        return 0;
    }
    do
    {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

void display(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "linked list empty" << endl;
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// inserting at beginning
void insertBeginning(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = new_node;

    Node *current = *head;
    if (current == NULL)
    {
        *head = new_node;
        return;
    }
    while (current->next != *head)
    {
        current = current->next;
    }
    new_node->next = *head;
    current->next = new_node;
    *head = new_node;
    return;
}

// inserting at end
void insertEnd(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = new_node;

    Node *current = *head;
    if (current == NULL)
    {
        *head = new_node;
        return;
    }
    while (current->next != *head)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return;
}

// deleting from end
void deleteEnd(Node **head)
{
    Node *current = *head;
    Node *prev = NULL;
    if (current == NULL)
    {
        cout << "Empty Linked List." << endl;
        return;
    }
    while (current->next != *head)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    delete current;
    return;
}

// deleting from beginning
void deleteBeginning(Node **head)
{
    Node *current = *head;
    Node *prev = *head;
    if (*head == NULL)
    {
        cout << "Empty Linked List." << endl;
        return;
    }

    while (prev->next != *head)
    {
        prev = prev->next;
    }
    prev->next = current->next;
    *head = prev->next;
    delete current;
}

int main()
{
    Node *head = NULL;
    insertEnd(&head, 14);
    insertEnd(&head, 2);
    insertEnd(&head, 45);
    display(head);
    cout << "Number of nodes: " << numberNodes(head) << endl;
    insertBeginning(&head, 99);
    cout << "After inserting at beginning: " << endl;
    display(head);
    deleteEnd(&head);
    cout << "After deleting from end: " << endl;
    display(head);
    deleteBeginning(&head);
    cout << "After deleting from beginning: " << endl;
    display(head);
    return 0;
}