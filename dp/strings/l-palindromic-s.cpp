#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
  {
    if (ind1 == 0 || ind2 == 0)
      return 0;

    if (dp[ind1][ind2] != -1)
      return dp[ind1][ind2];

    if (s[ind1 - 1] == t[ind2 - 1])
      return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s, t, dp);
    return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, s, t, dp),
                                solve(ind1, ind2 - 1, s, t, dp));
  }
  int tab(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
  {
    // dp[0][0] = (s[0]==t[0]);

    for (int i = 0; i <= ind1; i++)
      dp[i][0] = 0;
    for (int i = 0; i <= ind2; i++)
      dp[0][i] = 0;

    for (int i = 1; i <= ind1; i++)
    {
      for (int j = 1; j <= ind2; j++)
      {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[ind1][ind2];
  }
  int longestCommonSubsequence(string text1, string text2)
  {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return tab(n, m, text1, text2, dp);
  }
  int longestPalindromeSubseq(string s)
  {
    string temp = s;
    reverse(s.begin(), s.end());
    return longestCommonSubsequence(temp, s);
  }
};