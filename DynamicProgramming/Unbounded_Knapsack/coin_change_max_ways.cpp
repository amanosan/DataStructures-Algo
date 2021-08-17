#include <bits/stdc++.h>
using namespace std;
/*
Coin Change - Max number of ways:
Given a value N, if we want to make change for N cents, 
and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? 
The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, 
There are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.

THE PROBLEM IS SIMILAR TO NUMBER OF SUBSETS WITH GIVEN SUM (IN KNAPSACK).
BUT HERE WE WILL BE USING THE UNBOUNDED KNAPSACK CONCEPT.
*/
int coin_change_max_ways(int coin[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int coin[] = {2, 5, 3, 6};
    int sum = 10;
    int n = sizeof(coin) / sizeof(coin[0]);
    // the output should be 5.
    cout << coin_change_max_ways(coin, n, sum) << "\n";
    return 0;
}