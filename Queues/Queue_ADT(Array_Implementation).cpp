// Implementation of Queue using Arrays
#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int size, rear, front;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }

    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }

    // inserting into queue
    void enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            rear++;
            Q[rear] = x;
        }
    }

    // deleting from the queue
    void dequeue()
    {
        int deleted = -1;
        if (rear == front)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else
        {
            deleted = Q[front + 1];
            front++;
        }
        cout << deleted << " is deleted." << endl;
    }

    // to display the queue
    void display()
    {
        cout << "Front: ";
        for (int i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    q.dequeue(); // this will give error
    q.enqueue(13);
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(39);
    q.enqueue(77); // this will give error
    q.display();
    q.dequeue();
    q.display();

    return 0;
}