#include <bits/stdc++.h>
using namespace std;

/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in 
which order to perform the multiplications.

Example:
Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
*/

// matrix chain multiplication recursive
int mcm_recursive(int arr[], int i, int j)
{
    // i will be from 1, since we need arr[i-1] and arr[i] for dimension of matrix i
    // j will be till n-1, since we need arr[j-1] and arr[j]
    int ans = INT_MAX;
    // base condition, i cannot be greater or equal to j
    // this is because we need at least an array of size 2 so that we have
    // arr[i-1] and arr[i]
    if (i >= j)
        return 0;

    /*
    k goes from i to j-1.
        - 1st partition will be from i to k
        - 2nd partition will be from k+1 to j.
    if k goes till j, the second partition ie. from k+1 to j will be empty.
    */
    for (int k = i; k <= j - 1; k++)
    {
        int temp_cost = mcm_recursive(arr, i, k) + mcm_recursive(arr, k + 1, j) +
                        (arr[i - 1] * arr[k] * arr[j]);

        if (temp_cost < ans)
            ans = temp_cost;
    }
    return ans;
}

// matrix chain multiplication using bottom-up approach ie. memoization

// dimension of matrix will be size of array
// let's say we are given that size of array is at most 100:
int dp[101][101];
int mcm_memoized(int arr[], int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    if (i >= j)
    {
        dp[i][j] = 0;
        return dp[i][j];
    }
    for (int k = i; k <= j - 1; k++)
    {
        int temp_cost = mcm_memoized(arr, i, k) + mcm_memoized(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        dp[i][j] = min(ans, temp_cost);
    }
    return dp[i][j];
}

int main()
{
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 1, j = n - 1;
    memset(dp, -1, sizeof(dp));
    // output should be 30000
    cout << mcm_recursive(arr, i, j) << "\n";
    cout << mcm_memoized(arr, i, j) << "\n";
    return 0;
}