#include <bits/stdc++.h>
using namespace std;

// unbounded knapsack recursion
int unbounded_knapsack_recursion(int val[], int wt[], int n, int W)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] <= W)
        // the only difference here is that if we take the value, we call the function on the whole array again.
        // therefore, unbounded(val, wt, n, W-wt[n-1]) and not unbounded(val, wt, n-1, W-wt[n-1]);
        return max(
            val[n - 1] + unbounded_knapsack_recursion(val, wt, n, W - wt[n - 1]),
            unbounded_knapsack_recursion(val, wt, n - 1, W));
    else
        return unbounded_knapsack_recursion(val, wt, n - 1, W);
}

// unbounded knapsack top-down dynamic programming
int unbounded_knapsack(int val[], int wt[], int n, int W)
{
    int dp[n + 1][W + 1];

    // initializing
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;

    // main logic:
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int W = 100;
    int val[] = {1, 30};
    int wt[] = {1, 50};
    int n = sizeof(wt) / sizeof(wt[0]);
    // output should be 100
    cout << unbounded_knapsack_recursion(val, wt, n, W) << "\n";
    cout << unbounded_knapsack(val, wt, n, W) << "\n";
    return 0;
}