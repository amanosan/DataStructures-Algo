#include <bits/stdc++.h>
using namespace std;

/*
Boolean Parenthesization Problem
Given a boolean expression with the following symbols:
'T' - true
'F' - false
And following operators:
'&' - AND, '|' - OR, '^' - XOR

Count the number of ways we can parenthesize the expression so that the value of 
expression evaluates to true. 
*/

// boolean evaluation or evaluate boolean expression to TRUE recursive
int solve_recursive(string x, int i, int j, bool is_true)
{
    if (i > j)
        return false;

    if (i == j)
    {
        if (is_true == true)
            return x[i] == 'T';
        else
            return x[i] == 'F';
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        // two partitions -> i to k-1 and k+1 to j

        /*
        Getting the answers for teh subproblems:
        - We could want that the subproblem be evaluated to true or false
        - So we calculate ways for subproblem to be true and false both.
        */
        int left_t = solve_recursive(x, i, k - 1, true);   // left_subproblem = True
        int left_f = solve_recursive(x, i, k - 1, false);  // left_subproblem = False
        int right_t = solve_recursive(x, k + 1, j, true);  // right_subproblem = True
        int right_f = solve_recursive(x, k + 1, j, false); // right_subproblem = False

        // now we need to get the final answer
        char current_operator = x[k];

        // if operator is AND
        if (current_operator == '&')
        {
            // for true both should be true
            if (is_true == true)
                ans += (left_t * right_t);
            // for false one should be true and one should be false or both should be false
            else
                ans += (left_t * right_f) + (left_f * right_t) + (left_f * right_f);
        }

        // if operator is OR
        if (current_operator == '|')
        {
            // for true either or both should be true
            if (is_true == true)
                ans += (right_t * left_t) + (left_t * right_f) + (left_f * right_t);
            // for false both should be false
            else
                ans += (right_f * left_f);
        }

        // if operator is XOR
        if (current_operator == '^')
        {
            // for true both should be different
            if (is_true == true)
                ans += (right_t * left_f) + (right_f * left_t);
            // for false both should be same
            else
                ans += (right_t * left_t) + (right_f * left_f);
        }
    }
    return ans;
}

// boolean evaluation to TRUE memoized or bottom-up approach
/*
The Matrix will have three dimensions:
    - one for values of i
    - one for values of j 
    - one for values of is_true --> True or False, so dimension = 2.
    (both i and j will be dependent on the constraints and depend on the size of the string)
*/
int dp[101][101][2];
int solve_memoized(string x, int i, int j, bool is_true)
{
    // checking if value already calculated
    if (dp[i][j][is_true] != -1)
        return dp[i][j][is_true];

    // base condition
    if (i > j)
        return false;
    if (i == j)
    {
        if (is_true == true)
            return x[i] == 'T';
        else
            return x[i] == 'F';
    }

    // the main logic
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        // left partition = i to k-1, right partition = k+1 to j
        int left_t, left_f, right_t, right_f;

        // checking if left_t already exists:
        if (dp[i][k - 1][1] != -1)
            left_t = dp[i][k - 1][1];
        else
            // we calculate it:
            left_t = solve_memoized(x, i, k - 1, true);

        // checking if left_f already exists:
        if (dp[i][k - 1][0] != -1)
            left_f = dp[i][k - 1][0];
        else
            left_f = solve_memoized(x, i, k - 1, false);

        // checking if right_t already exists:
        if (dp[k + 1][j][1] != -1)
            right_t = dp[k + 1][j][1];
        else
            right_t = solve_memoized(x, k + 1, j, true);

        // checking if right_f already exists
        if (dp[k + 1][j][0] != -1)
            right_f = dp[k + 1][j][0];
        else
            right_f = solve_memoized(x, k + 1, j, false);

        char current_operator = x[k];
        if (current_operator == '&')
        {
            if (is_true == true)
                ans += (left_t * right_t);
            else
                ans += (left_t * right_f) + (left_f * right_t) + (right_f * left_f);
        }
        if (current_operator == '|')
        {
            if (is_true == true)
                ans += (left_t * right_t) + (left_f * right_t) + (left_t * right_f);
            else
                ans += (left_f * right_f);
        }
        if (current_operator == '^')
        {
            if (is_true == true)
                ans += (left_t * right_f) + (left_f * right_t);
            else
                ans += (left_t * right_t) + (left_f * right_f);
        }
        dp[i][j][is_true] = ans;
    }
    return dp[i][j][is_true];
}

int main()
{
    string x = "T|T&F^T";
    string y = "T^F&T";

    // output should be 4.
    memset(dp, -1, sizeof(dp));
    cout << solve_recursive(x, 0, x.length() - 1, true) << '\n';
    cout << solve_memoized(x, 0, x.length() - 1, true) << "\n";
    // output should be 2.
    memset(dp, -1, sizeof(dp));
    cout << solve_recursive(y, 0, y.length() - 1, true) << "\n";
    cout << solve_memoized(y, 0, y.length() - 1, true) << "\n";
    return 0;
}