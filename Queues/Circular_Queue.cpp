// Implementing Circular Queue
#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
private:
    int rear, front, size;
    int *Q;

public:
    CircularQueue()
    {
        rear = front = -1;
        size = 10;
        Q = new int[size];
    }

    CircularQueue(int size)
    {
        rear = front = -1;
        this->size = size;
        Q = new int[this->size];
    }

    bool isFull()
    {
        if (front == 0 && rear == size - 1)
            return true;
        if (front == rear + 1)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    // function to insert into Queue
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % size; // circling the value of rear
            Q[rear] = x;
        }
    }

    // function to delete from queue
    void dequeue()
    {
        int x;
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            x = Q[front];

            if (front == rear)
            {
                // resetting the Queue.
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % size; // circling the value of front
            }
        }
        cout << x << " has been deleted." << endl;
    }

    // function to display the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        {
            int i;
            for (i = front; i != rear; i = (i + 1) % size)
            {
                cout << Q[i] << " ";
            }
            cout << Q[i] << endl;
        }
    }
};

int main()
{
    CircularQueue q(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}