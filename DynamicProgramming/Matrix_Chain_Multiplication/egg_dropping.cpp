#include <bits/stdc++.h>
using namespace std;

/*
Problem statement: You are given N floor and K eggs. You have to minimize the 
number of times you have to drop the eggs to find the critical floor where critical 
floor means the floor beyond which eggs start to break. Assumptions of the problem:
    1. If egg breaks at ith floor then it also breaks at all greater floors.
    2. If egg does not break at ith floor then it does not break at all lower floors.
    3. Unbroken egg can be used again.

Example:
Input:
Floors: 36, Eggs: 2
Output:
Number of trials when number of eggs is 2 and number of floors is 36: 8

Input:
Floors: 4, Eggs: 2
Output:
Number of trials when number of eggs is 2 and number of floors is 4: 3

THIS PROBLEM IS A VARIATION IN MATRIX CHAIN MULTIPLICATION.
*/

// egg dropping recursive
int solve(int floor, int eggs)
{
    // base conditions
    // if we have one egg, we will start from bottom, so we could take f attempts:
    if (eggs == 1)
        return floor;
    // if we have 0 or just one floor, then we will need number of floor attempts
    if (floor == 0 or floor == 1)
        return floor;

    /*
    If we are at floor k and we drop the egg:
        - egg will break --> then it will break for all floors > k  ---> so we decrease k:
            - egg = egg - 1
            - floor = k - 1  --> number of floors remaining to check
        - egg wont break --> then it wont break for all floors < k  ---> so we increase k:
            - egg = egg
            - floor = floor - k  --> number of floors remaining to check
    */
    int ans = INT_MAX;
    for (int k = 1; k <= floor; k++)
    {
        // we need minimum number of attempts at worst case.
        // max is used since, we have to find guaranteed moves to find the breaking floor,
        // to find gurantee we take worst cases.
        // we add one since we have attempted once when we call both subproblems
        int temp = 1 + max(solve(k - 1, eggs - 1), solve(floor - k, eggs));
        ans = min(temp, ans);
    }
    return ans;
}

// egg dropping memoization, bottom-up approach
int dp[101][101];
int solve_memoize(int floors, int eggs)
{
    // if value is already computated
    if (dp[floors][eggs] != -1)
    {
        return dp[floors][eggs];
    }

    if (floors == 0 or floors == 1)
    {
        dp[floors][eggs] = floors;
        return dp[floors][eggs];
    }
    if (eggs == 1)
    {
        dp[floors][eggs] = floors;
        return dp[floors][eggs];
    }
    int ans = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        // int temp = 1 + max(solve_memoize(k - 1, eggs - 1), solve_memoize(floors - k, eggs));

        // we can optimize by checking if either of the subproblems has been computed before.
        int low, high;

        // checking if left subproblem exists already
        if (dp[k - 1][eggs - 1] != -1)
        {
            low = dp[k - 1][eggs - 1];
        }
        else
        {
            low = solve(k - 1, eggs - 1);
            dp[k - 1][eggs - 1] = low;
        }
        // checking if right subproblem exists already
        if (dp[floors - k][eggs] != -1)
        {
            high = dp[floors - k][eggs];
        }
        else
        {
            high = solve(floors - k, eggs);
            dp[floors - k][eggs] = high;
        }
        int temp = 1 + max(low, high);
        ans = min(temp, ans);
    }
    dp[floors][eggs] = ans;
    return dp[floors][eggs];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    // output should be 3
    cout << solve(4, 2) << "\n";
    // output should be 8
    cout << solve_memoize(36, 2) << "\n";
    return 0;
}