// Program to convert infix to postfix
#include <bits/stdc++.h>
#include <string>
using namespace std;

bool isOperand(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {
        return true;
    }
    return false;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string str)
{
    stack<char> s;
    s.push('(');
    int l = str.length();
    string postfix;

    for (int i = 0; i < l; i++)
    {

        // pushing the operands to the stack
        if (isOperand(str[i]))
        {
            postfix += str[i];
        }

        // if character is an operator
        else
        {
            while (precedence(str[i]) <= precedence(s.top()) && s.top() != '(')
            {
                char x = s.top();
                s.pop();
                postfix += x;
            }
            s.push(str[i]);
        }
    }
    // now popping remaining elements in the stack to the postfix
    while (s.top() != '(')
    {
        char x = s.top();
        s.pop();
        postfix += x;
    }
    return postfix;
}

int main()
{
    string infix = "a+b*c-d/e";
    string postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}