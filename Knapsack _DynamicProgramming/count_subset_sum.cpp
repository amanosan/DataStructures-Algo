#include <bits/stdc++.h>
using namespace std;

int count_subset_sum(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    // initializing the dp matrix
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }

    // main logic for the program
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
    int arr[] = {2, 3, 5, 6, 8};
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    auto result = count_subset_sum(arr, n, sum);
    cout << result << "\n";
    return 0;
}