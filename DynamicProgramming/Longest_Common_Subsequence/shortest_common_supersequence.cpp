#include <bits/stdc++.h>
using namespace std;
/*
Given two strings str1 and str2, the task is to find the length of the shortest string 
that has both str1 and str2 as subsequences.

Examples : 
Input:   str1 = "geek",  str2 = "eke"
Output: 5
Explanation: 
String "geeke" has both string "geek" 
and "eke" as subsequences.

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  9
Explanation: 
String "AGXGTXAYB" has both string 
"AGGTAB" and "GXTXAYB" as subsequences.
*/

/*
To get the common characters in both:
    - we can take longest common subsequence of x in y
    - or, we can take longest common subsequence of y in x

So to get the length of Shortest Supersequence:
- We merge both the strings.
- Then subtract the longest common subsequence that we calculated from above step.
- the remaining length will be the shortest supersequence.
*/
int shortest_common_supersequence(string x, string y, int n, int m)
{
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
    // total length (when we merge)
    int total_length = n + m;
    // length of common elements in both
    int lcs_length = dp[n][m];

    // length of shortest supersequence = total_length - lcs_length
    return total_length - lcs_length;
}

int main()
{
    string x = "AGGTAB", y = "GXTXAYB";
    // string x = "geek", y = "eke";
    int n = x.length(), m = y.length();
    auto result = shortest_common_supersequence(x, y, n, m);
    // output should be 9.
    cout << "Length of Shortest Common Supersequence: " << result;
    return 0;
}