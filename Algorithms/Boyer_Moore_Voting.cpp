// Given an array, find the majority element (frequency n/2)

#include <bits/stdc++.h>
using namespace std;

int findCandidate(vector<int> arr)
{
    int n = arr.size();
    int maj_index = 0, count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[maj_index])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return arr[maj_index];
}

bool validateCandidate(vector<int> arr, int cand)
{
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == cand)
            count++;
    }
    if (count > n / 2)
        return 1;
    else
        return 0;
}

int findMajority(vector<int> arr)
{
    int cand = findCandidate(arr);
    if (validateCandidate(arr, cand))
        return cand;
    else
        return -1;
}

int main()
{
    vector<int> arr({3, 3, 3, 2, 2, 2, 3});
    cout << findMajority(arr) << "\n";
    return 0;
}