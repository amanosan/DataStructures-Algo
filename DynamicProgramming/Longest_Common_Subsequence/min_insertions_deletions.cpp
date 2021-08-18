#include <bits/stdc++.h>
using namespace std;

/*
TO FIND MINIMUM NUMBER OF INSERTIONS AND DELETIONS TO CONVERT ONE STRING TO ANOTHER.
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. 
The task is to remove/delete and insert the minimum number of characters from/in 
str1 to transform it into str2. It could be possible that the same character needs to be 
removed/deleted from one point of str1 and inserted to some another point.

Example: 
Input :  str1 = "heap", str2 = "pea" 
Output : 
Minimum Deletion = 2 and
Minimum Insertion = 1

First we need to find the LCS of x in y.
- We will get ea. let length lcs_length = 2;
- Then from str1 we will find the deletions: str1.length - lcs_length
- Then from str2 we will find the insertions: str2.length - lcs_length

Length of str1 = 4
length of str2 = 3
Therefore, 
- DELETIONS ---> 4 - 2 = [2]
- INSERTIONS --> 3 - 2 = [1]
*/

void min_num_insertions_deletions(string x, string y)
{
    // we have to convert string x to y.
    int n = x.length();
    int m = y.length();
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

    int lcs_length = dp[n][m];
    int deletions = n - lcs_length;
    int insertions = m - lcs_length;

    cout << "Minimum Deletions: " << deletions << "\n";
    cout << "Minimum Insertions: " << insertions << "\n";
}

int main()
{
    string x = "geeksforgeeks", y = "geeks";
    // output should be, deletions=8, insertions=0
    min_num_insertions_deletions(x, y);
    return 0;
}