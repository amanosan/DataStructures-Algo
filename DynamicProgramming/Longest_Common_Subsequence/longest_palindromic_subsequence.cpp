#include <bits/stdc++.h>
using namespace std;

/*
Given a sequence, find the length of the longest palindromic subsequence in it.
Example:
If the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” 
is the longest palindromic subsequence in it. “BBBBB” and “BBCBB” are also palindromic 
subsequences of the given sequence, but not the longest ones.

To find the length:
- Simply reverse the given string str1 --> reverse(str1);
- Find the longest common subsequence of str1 and reverse(str1).

Example - "agbcba" and "abcbga" --> 
LCS = 5 and Longest palindromic subsequence is also 5 - "abcba"
*/

int longest_palindromic_subsequence(string x, int n)
{
    // reversing the string
    string y = x;
    reverse(y.begin(), y.end());

    // finding longest common subsequence between x and reverse(x) which is y
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int main()
{
    string x = "agbcba";
    int n = x.length();

    auto result = longest_palindromic_subsequence(x, n);
    cout << "Length of Longest Palindromic Subsequence: " << result << "\n";
    return 0;
}