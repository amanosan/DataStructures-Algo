// Stack implementation using Linked List
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    // function to push element into Stack
    void push(int number)
    {
        Node *temp = new Node();
        if (temp == NULL)
        {
            cout << "Error : Stack Overflow" << endl;
            return;
        }
        else
        {
            temp->data = number;
            temp->next = top;
            top = temp;
            return;
        }
    }

    // function to pop element from stack
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack  is empty." << endl;
            return;
        }

        Node *temp = top;
        top = temp->next;
        cout << temp->data << " has ben Popped." << endl;
        delete temp;
        return;
    }
    // function to peek at the top element
    int peek()
    {
        return top->data;
    }

    // function to check if the Stack is empty
    int isEmpty()
    {
        if (top == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // function to dispay the Stack
    void display()
    {
        cout << "Elements in the Stack are: ";
        while (top != NULL)
        {
            cout << top->data << " ";
            top = top->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(14);
    cout << "Element at top: " << s.peek() << endl;
    s.push(15);
    s.push(35);
    s.display();
    return 0;
}