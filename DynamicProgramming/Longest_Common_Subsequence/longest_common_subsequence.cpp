#include <bits/stdc++.h>
using namespace std;

// longest common subsequence recursive approach
int lcs_recursive(string x, string y, int n, int m)
{
    // n = size of x
    // m = size of y

    // base case
    if (n == 0 || m == 0)
        return 0;

    // choice diagram
    if (x[n - 1] == y[m - 1])
    {
        // returning 1 + lcs, because we have found matching characters.
        return 1 + lcs_recursive(x, y, n - 1, m - 1);
    }
    else
    {
        return max(lcs_recursive(x, y, n, m - 1), lcs_recursive(x, y, n - 1, m));
    }
}

int t[101][101];
// memoization of longest common subsequence
int lcs_memoization(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    // checking to see if value already exists.
    if (t[n][m] != -1)
        return t[n][m];

    if (x[n - 1] == y[m - 1])
    {
        t[n][m] = 1 + lcs_memoization(x, y, n - 1, m - 1);
        return t[n][m];
    }
    else
    {
        t[n][m] = max(lcs_memoization(x, y, n - 1, m), lcs_memoization(x, y, n, m - 1));
        return t[n][m];
    }
}

// longest common subsequence using top-down (tabulation)
int lcs_topdown(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // initializing
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    // setting each value to -1.
    memset(t, -1, sizeof(t));

    string x = "aggtab", y = "gxtxayb";
    // output should be 4
    cout << lcs_recursive(x, y, x.length(), y.length()) << "\n";
    cout << lcs_memoization(x, y, x.length(), y.length()) << "\n";
    cout << lcs_topdown(x, y, x.length(), y.length()) << "\n";
    return 0;
}