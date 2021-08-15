#include <bits/stdc++.h>
using namespace std;
/*
We need to find if the array can be divided into two subsets of equal sum.
*/
int equal_sum_partition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // sum of array should be an even number to break it into 2 partitions of equal sum.
    if (sum % 2 != 0)
        return false;

    // if the sum of the array is even,
    // we need to find a subset of array with sum = array_sum / 2
    // if we can find the subset who's sum is array sum by 2, then we can automatically say that there
    // will be another subset with the same sum.
    // so for even sum in array, the problem is nothing but subset sum problem.
    else
    {
        // we need to find subset with W = sum / 2:
        int W = sum / 2;
        int dp[n + 1][W + 1];

        // initializing the dp matrix
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
}

int main()
{
    int arr[] = {1, 5, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (equal_sum_partition(arr, n))
        cout << "YES\n";
    else
        cout << "NO\n";
}