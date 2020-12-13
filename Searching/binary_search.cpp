// Binary Search in array
// NOTE: The array passed to the function should be sorted.
#include <bits/stdc++.h>
using namespace std;

// iterative solution
int binarySearch(vector<int> v, int lower, int higher, int element)
{
    while (lower <= higher)
    {
        int mid = (lower + (higher - 1)) / 2;
        // checking if mid is the element
        if (v[mid] == element)
            return mid;

        if (v[mid] > element)
            higher = mid - 1;
        else
            lower = mid + 1;
    }
    return -1;
}

// recursive solution
int binarySearchRecursive(vector<int> &v, int l, int h, int x)
{
    while (l <= h)
    {
        int mid = (l + (h - 1)) / 2;
        if (v[mid] == x)
            return mid;

        if (v[mid] < x)
        {
            return binarySearchRecursive(v, mid + 1, h, x);
        }

        return binarySearchRecursive(v, l, mid - 1, x);
    }
    return -1;
}

// function to display vector
void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
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
    sort(v.begin(), v.end()); // sorting the array before passing to the function
    display(v);
    cout << "Enter element to search for: ";
    cin >> x;
    cout << "Element found at index: " << binarySearch(v, 0, v.size(), x) << endl;
    cout << "Element found at index: " << binarySearchRecursive(v, 0, v.size(), x) << endl;
    return 0;
}