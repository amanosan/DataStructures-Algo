/*
Given an array, find subsets where difference of the two subsets is k.

Let s1 and s2 be the sum of the two subsets.

s1 - s2 = k
s1 + s2 = sum (sum = sum of array)

From above two equations we can get:
s1 = (sum + k) / 2;

Now the problem is of finding subsets in array with sum equal to s1 (which we have already done).
*/

#include <bits/stdc++.h>
using namespace std;

int num_subset_with_given_difference(int arr[], int n, int k)
{
    int sum_array = 0;
    for (int i = 0; i < n; i++)
        sum_array += arr[i];

    // we need to find number of subsets with sum:
    int sum = (sum_array + k) / 2;

    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = {1, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 1;
    cout << num_subset_with_given_difference(arr, n, k) << "\n";
    return 0;
}