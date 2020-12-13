// Linear Search in array
#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> v, int element)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == element)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> v;
    int n, x;
    cout << "Enter number of elements in array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
    cout << "Enter element to search for: ";
    cin >> x;
    cout << "Element found at index: " << linearSearch(v, x) << endl;
    return 0;
}