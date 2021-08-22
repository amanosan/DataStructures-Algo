#include <bits/stdc++.h>
using namespace std;

/*
Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.
Scrambled string: 
Given string str, we can represent it as a binary tree by partitioning it into two 
non-empty substrings recursively.

Examples:
Input: S1=”coder”, S2=”ocder” 
Output: Yes 
Explanation: 
“ocder” is a scrambled form of “coder”
Input: S1=”abcde”, S2=”caebd” 
Output: No 
Explanation: 
“caebd” is not a scrambled form of “abcde”
*/

// scrambled string problem recursive
bool solve_recursive(string x, string y)
{
    int n = x.length();

    // edge conditions
    if (x.length() != y.length())
        return false;
    // empty string are scrambled
    if (n == 0)
        return true;

    // if strings are equal
    if (x == y)
        return true;

    // lets check if all characters are same
    string x_copy = x, y_copy = y;
    sort(x_copy.begin(), x_copy.end());
    sort(y_copy.begin(), y_copy.end());

    if (x_copy != y_copy)
        return false;

    // now checking for scrambled substrings
    for (int i = 1; i < n; i++)
    {
        if (solve_recursive(x.substr(0, i), y.substr(0, i)) && solve_recursive(x.substr(i, n - i), y.substr(i, n - i)))
        {
            return true;
        }

        if (solve_recursive(x.substr(0, i), y.substr(n - i, n)) && solve_recursive(x.substr(i, n - i), y.substr(0, n - i)))
        {
            return true;
        }
    }
    return false;
}

// scrambled string problem memoized, bottom-up apprach
unordered_map<string, bool> mp; // to store the already computed strings
bool solve_memoize(string x, string y)
{
    int n = x.length();
    int m = y.length();
    if (n != m)
        return false;

    if (n == 0)
        return true;

    if (x == y)
        return true;

    string x_copy = x, y_copy = y;
    sort(x_copy.begin(), x_copy.end());
    sort(y_copy.begin(), y_copy.end());
    if (x_copy != y_copy)
        return false;

    string key = x + " " + y;

    // checking if value has been calculated for both strings
    if (mp.find(key) != mp.end())
        return mp[key];

    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (solve_recursive(x.substr(0, i), y.substr(0, i)) && solve_recursive(x.substr(i, n - i), y.substr(i, n - i)))
        {
            flag = true;
            break;
        }

        if (solve_recursive(x.substr(0, i), y.substr(n - i, n)) && solve_recursive(x.substr(i, n - i), y.substr(0, n - i)))
        {
            flag = true;
            break;
        }
    }
    // setting the value in the map for key:
    mp[key] = flag;

    // if no condition satisfies then we return false
    return flag;
}

int main()
{
    string x = "great";
    string y = "grate";
    string x1 = "abcde";
    string y1 = "caebd";
    // clearing the unordered map
    mp.clear();

    // output should be true ie. 1.
    cout << solve_recursive(x, y) << "\n";
    cout << solve_memoize(x, y) << "\n";

    // clearing the unorder_map
    mp.clear();
    //output should be false ie. 0
    cout << solve_recursive(x1, y1) << "\n";
    cout << solve_memoize(x1, y1) << "\n";
    return 0;
}