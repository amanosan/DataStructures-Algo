#include <bits/stdc++.h>
using namespace std;
/*
Given a value V, if we want to make change for V cents, and we have infinite supply of each of 
C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change? 
If it’s not possible to make change, print -1.

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents
*/

int min_number_coins(int coins[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    // initializing
    /*
    When we have coins = [] ie. we have size of array as 0:
    for making sum as any number we mathematically need infinite number of coins.
    ie. INT_MAX - 1;
    dp[0][0......sum] = INT_MAX - 1;

    When we have sum to make 0 and we have size of array as greater than equal to 1:
    then we can select no coin or 0 coins. ie to have sum as 0 we need 0 minimum coins, so,
    dp[1....n][0] = 0;

    */

    // initialization of dp matrix
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= sum; i++)
        dp[0][i] = INT_MAX - 1;
    for (int i = 1; i <= sum; i++)
    {
        if (i % coins[0] == 0)
            dp[1][i] = i / coins[0];
        else
            dp[1][i] = INT_MAX - 1;
    }

    /*
    If the value of coin[i-1] is less than the current sum, we have two choices
        - selecting = 1 + dp[i][j - coins[i-1]]  // since we are selecting the current coin as well we add 1
        - not selecting = dp[i-1][j]
        And we select the minimum of the two.

    NOTE: we are not storing INT_MAX and instead using INT_MAX - 1 because in the above case there might
    be a case where we need to add 1 to INT_MAX.
    If we add 1 to INT_MAX, we will get an error and therefore we store it as INT_MAX - 1.
    
    Else, we have only one option of not selecting = dp[i-1][j];
    */
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int coins[] = {10, 25, 5};
    int sum = 30;
    int n = sizeof(coins) / sizeof(coins[0]);
    // output should be 2.
    cout << min_number_coins(coins, n, sum) << "\n";
    return 0;
}