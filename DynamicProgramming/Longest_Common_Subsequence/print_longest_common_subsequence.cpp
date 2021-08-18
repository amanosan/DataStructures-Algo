#include <bits/stdc++.h>
using namespace std;

// printing the longest common subsequence
void print_lcs(string x, string y, int n, int m)
{
    // calculating the matrix for longest common subsequence
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

    // printing the longest common subsequence.
    string lcs;
    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        // if the characters matches, we insert character to lcs string.
        if (x[i - 1] == y[j - 1])
        {
            lcs.push_back(x[i - 1]);
            // going to the diagonal element.
            i--;
            j--;
        }
        else
        {
            // if characters don't match, we go to the direction of maximum value.
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    // reversing the string
    reverse(lcs.begin(), lcs.end());
    cout << lcs << "\n";
}

int main()
{
    string x = "aggtab", y = "gxtxayb";
    int n = x.length(), m = y.length();
    print_lcs(x, y, n, m); // gtab
    return 0;
}