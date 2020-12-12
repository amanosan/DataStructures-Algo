// Program to check if the string has Balanced Parantheses.
// This program will not check if the parantheses are proper or not.
#include <bits/stdc++.h>
using namespace std;

// this function only handles '()'
bool isBalancedParantheses(string expression)
{
    stack<char> s;

    for (int i = 0; i < expression.size(); i++)
    {
        // adding all the open brackets into the stack
        if (expression[i] == '(')
        {
            s.push(expression[i]);
            continue;
        }
        if (expression[i] == ')')
        {
            if (s.empty())
            {
                return false;
            }
            s.pop();
        }
    }
    return (s.empty());
}

// this function handles all the brackets including '[]', '{}', '()'
bool balancedString(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {

        // checking for opening brackets
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }

        // checking if its a closing bracket
        char x;
        switch (str[i])
        {
        case ')':
            x = s.top();
            s.pop();
            if (x == '[' || x == '{')
            {
                return false;
            }
            break;

        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
            {
                return false;
            }
            break;

        case ']':
            x = s.top();
            s.pop();
            if (x == '{' || x == '(')
            {
                return false;
            }
            break;

        deafult:
            continue;
            break;
        }
    }

    return (s.empty());
}

int main()
{
    string str = "(A+B) + (D+E+F))";
    bool ans = isBalancedParantheses(str);

    if (ans == 0)
        cout << "String is not balanced." << endl;
    else
        cout << "String is balanced." << endl;

    return 0;
}