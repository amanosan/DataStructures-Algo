#include <bits/stdc++.h>
using namespace std;

// pattern matching using two pointer approach
bool pattern_matching(string x, string y)
{
    // to check if x is a subsequence of y
    int n = x.length(), m = y.length();
    int i = 0, j = 0;
    string result;
    while (i < n and j < m)
    {
        if (x[i] == y[j])
        {
            result.push_back(x[i]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if (x == result)
        return true;
    return false;
}

// pattern matching using longest common subsequence (dp) approach
bool pattern_matrching_lcs(string x, string y)
{
    int n = x.length(), m = y.length();
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
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
    int len_lcs = dp[n][m];
    if (n == len_lcs)
        return true;
    return false;
}

int main()
{
    string x = "axy";
    string y = "adxcpy";
    // output should be 1
    cout << "result: " << pattern_matching(x, y) << "\n";
    cout << "result: " << pattern_matrching_lcs(x, y) << "\n";
    return 0;
}