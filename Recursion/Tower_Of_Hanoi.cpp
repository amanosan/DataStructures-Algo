#include <bits/stdc++.h>
using namespace std;
int count = 0;

void towerOfHanoi(int numberOfDisks, int tower1, int tower2, int tower3)
{
    if (numberOfDisks > 0)
    {
        towerOfHanoi(numberOfDisks - 1, tower1, tower3, tower2);
        cout << "From " << tower1 << " to " << tower3 << endl;
        towerOfHanoi(numberOfDisks - 1, tower2, tower1, tower3);
        ::count++;
    }
}

int main()
{
    int n = 3, a = 1, b = 2, c = 3;
    cout << "Steps to be followed to solve are :" << endl;
    towerOfHanoi(n, a, b, c);
    cout << "Total number of steps required are: " << ::count << endl;
    return 0;
}