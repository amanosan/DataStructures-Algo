// Stack implementation using Arrays
#include <bits/stdc++.h>
using namespace std;

#define MAX 5

class Stack
{
private:
    int top;

public:
    int a[MAX];

    // constructor function to initialize stack
    Stack()
    {
        top = -1;
    }

    // function to push element
    void push(int number)
    {
        if (top == MAX - 1)
        {
            cout << "Error: Stack Overflow." << endl;
            return;
        }
        else
        {
            a[++top] = number;
            return;
        }
    }

    // function to pop element
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Empty" << endl;
            return;
        }
        top--;
    }

    // function to get the value of top
    int getTop()
    {
        return top;
    }

    // function to check whether stack is empty or not
    void isEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack is not empty" << endl;
        }
    }

    // funciton to display the stack
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.isEmpty();
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    s.isEmpty();
    cout << "Top is at index: " << s.getTop() << endl;
    return 0;
}