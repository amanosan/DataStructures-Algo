// Linked List

#include <bits/stdc++.h>
using namespace std;

// Creating Node for the class
struct Node
{
    int data;
    Node *next;
};

// function to count the number of nodes
int numberOfNodes(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}
// print function iterative
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// print function using recursion
void displayRecursion(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";    // printing the value in the node
    displayRecursion(head->next); // calling function with next node
}

// print in reverse order using recursion
void displayReverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    // in case of reverse we will go down to the last node and then print it
    displayReverse(head->next);
    cout << head->data << " ";
}

// INSERTION TO LINKED LIST

// function to insert in the beginning of the linked list
void insertAtBeginning(Node **ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data; // entering data
    new_node->next = (*ref);   // pointing new node to the current head of the list
    (*ref) = new_node;         // making the new node as the header of the list.
}

// function to insert at the end of the linked list
void insertAtEnd(Node **ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    //checking if the list is empty
    if (*ref == NULL)
    {
        *ref = new_node;
        return;
    }
    Node *last = (*ref);
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

// function to insert at nth position of the linked list
void insertAtPosition(Node **ref, int new_data, int position)
{
    Node *ptr_position = (*ref); // creating pointer to Node for inserting at postiion
    Node *new_node = new Node(); // creating a new node for the linked list
    new_node->data = new_data;   // storing the data into the node

    // if inserting at position 0
    if (position == 0)
    {
        new_node->next = (*ref);
        *ref = new_node;
        return;
    }

    // checking if position is valid or not
    if (position > numberOfNodes(ptr_position))
    {
        cout << "Position invalid." << endl;
        return;
    }

    for (int i = 0; i < (position - 1); i++)
    {
        ptr_position = ptr_position->next;
    }
    new_node->next = ptr_position->next;
    ptr_position->next = new_node;
    return;
}

// DELETION IN LINKED LIST

// function to delete from the beginning
void deleteFromBeginning(Node **ref)
{
    Node *temp = (*ref);
    (*ref) = temp->next;
    delete temp;
    return;
}

// function to delete from end of linked list
void deleteFromEnd(Node **ref)
{
    Node *temp = (*ref);
    Node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    return;
}

// function to delete node with key value
void deleteFromKey(Node **ref, int key)
{
    Node *temp = (*ref);
    Node *prev = NULL;

    // checking if linked list is empty
    if (temp == NULL)
    {
        cout << "Linked List is empty." << endl;
    }

    // now checking if header holds the key
    if (temp != NULL && temp->data == key)
    {
        (*ref) = temp->next;
        delete temp;
        return;
    }

    // now traversing to find the previous node
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // checking if the key is not in the list
    if (temp == NULL)
    {
        cout << "Element not present in the Linked List" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    return;
}

// function to delete node from position
void deleteFromPosition(Node **ref, int position)
{
    Node *temp = (*ref);
    Node *prev;

    // checking if linked list is empty
    if (temp == NULL)
    {
        cout << "Linked List Empty" << endl;
        return;
    }

    // checking if position is beginning
    if (position == 0)
    {
        (*ref) = temp->next;
        delete temp;
        return;
    }

    // now going to the previous pointer
    for (int i = 0; i < (position); i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    return;
}

// DELETING WHOLE LINKED LIST
void deleteLinkedList(Node **ref)
{
    Node *temp;
    Node *iterator = (*ref);
    while (iterator)
    {
        temp = iterator->next;
        delete (iterator);
        iterator = temp;
    }
    *ref = NULL;
    return;
}

// REVERSING LINKED LIST

// iterative solution
void reverseIter(Node **ref)
{
    Node *current = (*ref);
    Node *prev = NULL, *temp = NULL;

    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*ref) = prev;
    return;
}

int main()
{
    Node *head = NULL;
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 13);
    insertAtPosition(&head, 99, 0);
    insertAtEnd(&head, 35);
    insertAtEnd(&head, 78);
    insertAtEnd(&head, 66);
    insertAtEnd(&head, 54);
    cout << "Before deleting: " << endl;
    display(head);
    // deleteFromPosition(&head, 3);
    // deleteFromBeginning(&head);
    // deleteFromEnd(&head);
    // deleteFromKey(&head, 35);
    // cout << "After deletion processes: " << endl;
    // display(head);
    // cout << "After deleting the Linked List: " << endl;
    // // deleteLinkedList(&head);
    // display(head);
    displayRecursion(head);
    return 0;
}
