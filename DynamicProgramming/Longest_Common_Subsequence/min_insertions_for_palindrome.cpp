#include <bits/stdc++.h>
using namespace std;

/* 
Minimum number of insertions to make the string a palindrome.

Given a string str, the task is to find the minimum number of characters 
to be inserted to convert it to palindrome.
Examples:
Input: abcda
Output: 2 --> adcbcda

Input: abcde
Output: 4 --> abcdedbca
*/
int insertions_for_palindrome(string x)
{
    int n = x.length();
    string y = x;
    reverse(y.begin(), y.end());

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

    int len_lcs = dp[n][n];
    int insertion = n - len_lcs;
    return insertion;
}

int main()
{
    string x = "abcde";
    // output should be 4.
    auto result = insertions_for_palindrome(x);
    cout << "Minimum Insertions for Palindrome: " << result << "\n";
    return 0;
}