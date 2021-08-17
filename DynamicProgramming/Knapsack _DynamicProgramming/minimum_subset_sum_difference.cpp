#include <bits/stdc++.h>
using namespace std;

int min_subset_sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // the last row of dp[i][j] will tell whether we have a subset with sum equal to j
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    /*
        we have two partitions - p1 and p2 - with sum s1 and s2, we assume s1 is smaller.

        We want to minimize (s2 - s1)
        range = sum of array
        The range of s1 as we saw can be from 0 to range, so s2 = range - s1, because s1 + s2 = range.
        
        so now we have,
            s2 = range - s1
            minimize(s2 - s1) == minimize(range - s1 - s1)
            minimize(range - 2s1)

        NOTE: s1 will lie between 0 and range/2.
        and to find the valid values for s1 we have used the subset sum problem to check whether s1
        can have a value or not.
        the last row will tell if we have all the elements whether a given sum j can be made or not.
    */

    // finding candidate values of s1 from subset sum problem:
    vector<int> valid_values;
    for (int i = 0; i <= sum / 2; i++)
    {
        // checking if subset sum can be made or not in the last row of the dp matrix:
        if (dp[n][i] == 1)
        {
            valid_values.push_back(i); // storing the value of s1
        }
    }

    // uncomment to check the valid values which s1 can take.
    // for(auto x: valid_values)
    //     cout << x << " ";

    int min_value = INT_MAX; // this will store the final answer.
    for (int i = 0; i < valid_values.size(); i++)
    {
        // minimimizing (range - 2*s1), where range = sum of array.
        min_value = min(min_value, sum - (2 * valid_values[i]));
    }
    return min_value;
}

int main()
{
    int arr[] = {1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << min_subset_sum(arr, n);
    return 0;
}