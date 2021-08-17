#include <bits/stdc++.h>
using namespace std;

/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size 
smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, if the length of the rod is 8 and the values of different pieces are given as the following,
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

THIS IS A PROBLEM SIMILAR TO UNBOUNDED KNAPSACK
*/

int rod_cutting(int length[], int price[], int n, int L)
{
    int dp[n + 1][L + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= L; j++)
        {
            // initializing the array
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (length[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][L];
}

int main()
{
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price1[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int price2[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price1) / sizeof(price1[0]);
    int L = 8;
    // output should be 22
    cout << rod_cutting(length, price1, n, L) << "\n";
    // output should be 24
    cout << rod_cutting(length, price2, n, L) << "\n";
    return 0;
}