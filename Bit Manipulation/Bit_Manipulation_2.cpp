#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// function to find the bit in ith position in the number
int findBit(int number, int i)
{
    // zero based indexing
    int mask = 1;
    // we first left shift number "1" i times
    mask = mask << i;
    // if mask and number is non zero then bit value is 1
    if ((mask & number) != 0)
        return 1;
    // if mask and number is zero then bit value is 0
    else
        return 0;
}

// function to set a bit 1 at index i in the number (change bit 0 to 1)
int setBit(int number, int i)
{
    // zero based indexing
    int mask = 1 << i; // shifting number "1" i times
    // now instead of and operator we will use or operator
    int n = (number | mask);
    return n;
}

// function to clear bit at index i in the number (change bit 1 to 0)
int clearBit(int number, int i)
{
    // inverting the mask after left shifting
    int mask = ~(1 << i);
    return (number & mask);
}

// function to find number of set bits (bits with value 1)
// time complexity - number of bits in the number
int numberSetBits(int number)
{
    // the logic is to right shift and find if bit is 1 or not
    // if bit is 1, count++ else just right shift
    int count = 0;
    while (number != 0)
    {
        if ((number & 1) != 0)
        {
            count++;
            number = number >> 1;
        }
        else
        {
            number = number >> 1;
        }
    }
    return count;
}

// optimized function to find set bits in the number
// time complexity - number of set bits in the number
int numberSetBitsOptimized(int number)
{
    int count = 0;
    while (number != 0)
    {
        number = (number & (number - 1));
        count++;
    }
    return count;
}

// function to find the number of bits in its binary format
int numberOfBits(int number)
{
    return log2(number) + 1;
}

// function to find number of bits to change to convert a to b
int bitsToChange(int a, int b)
{
    // logic is to find number of different bits in the number (XOR the two numbers)
    // then find the number of set bits(bit with value 1) in the answer of XOR.

    int answer_xor = (a ^ b);
    // return numberSetBits(answer_xor);
    return numberSetBitsOptimized(answer_xor);
}

int main()
{
    int n1 = 15; // binary = 1111
    int n2 = 19; // binary = 10011
    int n3 = 18; // binary = 10010
    for (int i = 4; i >= 0; i--)
    {
        cout << findBit(n2, i); // output should be 10011
    }
    cout << endl;
    cout << setBit(n3, 0) << endl;     // output should be 19
    cout << clearBit(n2, 0) << endl;   // output should be 18
    cout << numberSetBits(n1) << endl; // output should be 4
    cout << numberSetBitsOptimized(n1) << endl;

    // number of bits to change toget 18 from 19 or vice-versa
    cout << bitsToChange(n2, n3) << endl; // output should be 1

    // number of bits in number
    cout << numberOfBits(n2) << endl; // output should be 5
    return 0;
}