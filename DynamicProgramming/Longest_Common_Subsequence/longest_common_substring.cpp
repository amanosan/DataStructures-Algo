#include <bits/stdc++.h>
using namespace std;
/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 
Examples:
Input : X = “abcdxyz”, y = “xyzabcd” 
Output : 4 
Explanation:
The longest common substring is “abcd” and is of length 4.

THIS PROBLEM IS SIMILAR TO LONGEST COMMON SUBSEQUENCE.
The main difference is that if the characters don't match we set the length to 0.
We also store the result and keep checking for maximum length of substring.
*/
int longest_common_substring(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    int result = INT_MIN; // to store the final result.

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                // checking if we have any previous substring with greater length
                result = max(result, dp[i][j]);
            }
            else
                // since the characters don't match we set the length to be 0.
                dp[i][j] = 0;
        }
    }
    return result;
}

int main()
{
    string x = "abcdxyz";
    string y = "xyzabcd";
    int n = x.length(), m = y.length();
    // output should be 4.
    cout << longest_common_substring(x, y, n, m) << "\n";
    return 0;
}