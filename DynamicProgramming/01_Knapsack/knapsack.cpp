#include <bits/stdc++.h>
using namespace std;

int knapsack_recursion(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;

    // if weight is greater than capacity of nth element, we don't include it.
    if (wt[n - 1] > W)
        return knapsack_recursion(wt, val, W, n - 1);

    else
        return max(
            val[n - 1] + knapsack_recursion(wt, val, W - wt[n - 1], n - 1), // if we take nth element.
            knapsack_recursion(wt, val, W, n - 1)                           // if we don't take nth element.
        );
}

int knapsack_topdown(int wt[], int val[], int W, int n)
{
    int dp[n + 1][W + 1];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 or w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack_recursion(wt, val, W, n) << "\n";
    cout << knapsack_topdown(wt, val, W, n);
    return 0;
}