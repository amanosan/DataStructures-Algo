#include <bits/stdc++.h>
using namespace std;

/*
Given two strings X and Y, print the shortest string that has both X and Y as subsequences. 
If multiple shortest supersequence exists, print any one of them.

Examples: 
Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y
*/

void print_shortest_common_supersequence(string x, string y)
{
    int n = x.length();
    int m = y.length();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
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
    int len_supersequence = (m + n) - dp[n][m];

    // printing the supersequence
    int i = n, j = m;
    string result;
    while (i > 0 and j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            result.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                // we will include this character in the supersequence as well
                result.push_back(x[i - 1]);
                i--;
            }
            else
            {
                // we will include this character in the supersequence as well
                result.push_back(y[j - 1]);
                j--;
            }
        }
    }

    // checking if we still have some characters left in either of the strings
    while (i > 0)
    {
        result.push_back(x[i - 1]);
        i--;
    }
    while (j > 0)
    {
        result.push_back(y[j - 1]);
        j--;
    }
    reverse(result.begin(), result.end());
    cout << result << "\n";
}

int main()
{
    string x = "AGGTAB", y = "GXTXAYB";
    // output should be "AGXGTXAYB" OR "AGGXTXAYB"
    print_shortest_common_supersequence(x, y);
    return 0;
}