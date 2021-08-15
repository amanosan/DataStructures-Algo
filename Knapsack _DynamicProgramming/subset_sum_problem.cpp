#include <bits/stdc++.h>
using namespace std;

int subset_sum_problem(int arr[], int sum, int n)
{
    bool dp[n + 1][sum + 1];

    // initialization of matrix
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true; // we can make 0 sum subset by taking null elements in subset, therefore true
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false; // since we cannot make subset sum equal to a value with 0 elements
    }

    // main logic similar to 0/1 knapsack
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // if value is less than the current target sum
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
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
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 102;
    int n = sizeof(set) / sizeof(set[0]);
    if (subset_sum_problem(set, sum, n) == true)
        cout << "YES\n";
    else
        cout << "NO\n";
}