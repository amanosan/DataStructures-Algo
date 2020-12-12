// Implementation of Queue ADT using Linked List.
#include <bits/stdc++.h>
using namespace std;

// linked list node.
class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front, *rear;

public:
    Queue()
    {
        rear = NULL;
        front = NULL;
    }

    bool isEmpty()
    {
        if (rear == NULL && front == NULL)
            return true;
        return false;
    }

    // function to insert into queue
    void enqueue(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;

        if (front == NULL)
        {
            front = new_node;
            rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
    }

    // function to delete from queue
    void dequeue()
    {
        int x = -1;
        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
        }
        else if (front == rear)
        {
            x = front->data;
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            front = temp->next;
            x = temp->data;
            delete temp;
        }
        if (x == -1)
        {
            cout << "Nothing deleted." << endl;
        }
        else
        {
            cout << x << " has been deleted" << endl;
        }
    }

    // function to display the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
        }
        else
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(13);
    q.enqueue(14);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}