#include <iostream>
using namespace std;

int main()
{
    int n1 = 5, n2 = 12;

    // bitwise operators:
    cout << (n1 & n2) << endl; // bitwise and operator
    cout << (n1 | n2) << endl; // bitwise or operator
    cout << (n1 ^ n2) << endl; // bitwise xor operator
    cout << ~(n1) << endl;     // not operator
    cout << (n2 >> 2) << endl; // right shift operator
    cout << (n2 << 2) << endl; // left shift operator

    // use of left and right shift operators to divide and multiply by two:
    int n3 = n2 >> 1; // right shifting by one leads to number divided by two
    cout << n3 << endl;
    int n4 = n2 << 1; // left shifting by one leads to multiplication by two
    cout << n4 << endl;

    // finding if number is even or odd
    // all even numbers in their binary form have 0 bit at the last place
    if ((n2 & 1) == 0)
        cout << n2 << " is Even" << endl; // if number and 1 is 0 then even
    else
        cout << n2 << " is Odd" << endl; // if number and 1 is 1 then odd

    // swapping two numbers using bit manipulation
    int a = 10, b = 20;
    a = (a ^ b);
    b = (a ^ b);
    a = (a ^ b);
    cout << a << " " << b << endl; // output should be 20 10
    return 0;
}