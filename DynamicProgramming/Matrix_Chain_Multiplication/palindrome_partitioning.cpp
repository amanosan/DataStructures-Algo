#include <bits/stdc++.h>
using namespace std;

/*
Given a string, a partitioning of the string is a palindrome partitioning if every 
substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a 
palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a 
palindrome partitioning of a given string.

Examples:
Input : str = “geek” 
Output : 2 
We need to make minimum 2 cuts, i.e., “g ee k”
Input : str = “aaaa” 
Output : 0 
The string is already a palindrome.
Input : str = “abcde” 
Output : 4
Input : str = “abbac” 
Output : 1 

THIS PROBLEM IS A VARIATION OF MATRIX CHAIN MULTIPLICATION.
*/

// function to check if string is palindrome
bool is_palindrome(string x, int start, int end)
{
    while (start <= end)
    {
        if (x[start] == x[end])
        {
            start++;
            end--;
        }
        else
            return false;
    }
    return true;
}

// palindrome partitioning recursive
int pp_recursive(string x, int i, int j)
{
    if (i >= j)
        return 0;

    if (is_palindrome(x, i, j))
        return 0;

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        // we add 1 since we have partitioned the string into two partitions
        // - 1st ---> i to k
        // - 2nd ---> k + 1 to j
        int temp = 1 + pp_recursive(x, i, k) + pp_recursive(x, k + 1, j);
        ans = min(ans, temp);
    }
    return ans;
}

// palindrome partitioning bottom-up ie. memoized appraoch
int dp[101][101];
int pp_memoized(string x, int i, int j)
{
    // checking if value is already calculated.
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i >= j)
    {
        dp[i][j] = 0;
        return dp[i][j];
    }
    if (is_palindrome(x, i, j))
    {
        dp[i][j] = 0;
        return dp[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        // int temp = 1 + pp_memoized(x, i, k) + pp_memoized(x, k + 1, j);

        /*
        Optimization:
        Before calling the functions recursively to get the value in temp,
        We will check if one or both subproblems have been solved already:
            - if (dp[i][k] != -1) --> already solved
            - if (dp[k+1][j] != -1)  --> already solved
        */
        int left_subproblem, right_subproblem;
        // checking for i to k subproblem
        if (dp[i][k] != -1)
            left_subproblem = dp[i][k];
        else
        {
            left_subproblem = pp_memoized(x, i, k);
            dp[i][k] = left_subproblem;
        }
        // similarly checking for k+1 to j
        if (dp[k + 1][j] != -1)
            right_subproblem = dp[k + 1][j];
        else
        {
            right_subproblem = pp_memoized(x, k + 1, j);
            dp[k + 1][j] = right_subproblem;
        }
        int temp = 1 + left_subproblem + right_subproblem;
        ans = min(temp, ans);
    }
    return dp[i][j] = ans;
}

int main()
{
    string x = "abcbd";
    memset(dp, -1, sizeof(dp));
    // the output should be 2, Partitions: a, bcb, d
    cout << pp_recursive(x, 0, x.length() - 1) << "\n";
    cout << pp_memoized(x, 0, x.length() - 1) << "\n";
    return 0;
}