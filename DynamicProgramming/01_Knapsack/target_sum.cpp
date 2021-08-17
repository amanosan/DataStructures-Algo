/*
Given an array, we need to find a target sum.
We can add or subtract the elements in order such that the sum of element is the target sum.

Example:
arr = [1, 1, 2, 3]
target = 1;

solution 1 - [-1, +1, -2, +3] ---> 1
solution 2 - [+1, -1, -2, +3] ---> 1
solution 3 - [+1, +1, +2, -3] ---> 1

If we think hard about it, this is nothing but Number of subsets with given difference.

We need to find two subsets with their difference equal to target:
if take solution 1 --> {-1, +1, -2, +3}
we have two subsets one with positive and one with negative elements
s1 = [1, 3]
s2 = [1, 2]
and we get target = s1 - s2
*/

#include <bits/stdc++.h>
using namespace std;

int target_sum(int arr[], int n, int k)
{
    int array_sum = 0;
    for (int i = 0; i < n; i++)
        array_sum += arr[i];

    int s1 = (array_sum + k) / 2;

    int dp[n + 1][s1 + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= s1; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][s1];
}

int main()
{
    int arr[] = {1, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 1;
    cout << target_sum(arr, n, k) << "\n";
    return 0;
}