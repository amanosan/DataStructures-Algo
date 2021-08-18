#include <bits/stdc++.h>
using namespace std;

/*
Minimum number of deletions to make a string palindrome.
Given a string of size ‘n’. The task is to remove or delete the minimum number
of characters from the string so that the resultant string is a palindrome. 

Note: The order of characters should be maintained. 

Example:
Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string.

- Reverse the string and find lcs of string and reverse(string).
- Subtract the lcs length from the length of string.
Example:
string = aebcbda
len of string, l = 7
reverse of string = adbcbea
lcs of "aebcbda" and "adbcbea" --> "abcba" - length = 5

Deletions = l - lcs lenth => 7 - 5 => [2]
*/

int min_deletions_for_palindrome(string x)
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

    int longest_palindrome_len = dp[n][n];
    int deletions = n - longest_palindrome_len;
    return deletions;
}

int main()
{
    string x = "aebcbda";
    auto result = min_deletions_for_palindrome(x);
    cout << "Minimum Deletions to make String Palindrome: " << result << "\n";
    return 0;
}