#include <bits/stdc++.h>
using namespace std;

/*
Longest Repeated Subsequence
Given a string, print the longest repeating subsequence such that the two subsequence 
don’t have same string character at same position, i.e., any i’th character in the two 
subsequences shouldn’t have the same index in the original string.

Examples:
Input: str = "aabb"
Output: "ab"
*/

int longest_repeating_subsequence(string x)
{
    int n = x.length();
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
            // if the index is not same and characters match, we take it:
            else if (x[i - 1] == x[j - 1] and (i != j))
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            //if the characters don't match:
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    string x = "aabebcdd";
    auto result = longest_repeating_subsequence(x);
    // output should be 3 ("ABD")
    cout << result << "\n";
    return 0;
}