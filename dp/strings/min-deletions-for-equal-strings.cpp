#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
  {
    if (ind1 < 0 || ind2 < 0)
      return 0;

    if (dp[ind1][ind2] != -1)
      return dp[ind1][ind2];
    if (s[ind1] == t[ind2])
      return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s, t, dp);
    return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, s, t, dp),
                                solve(ind1, ind2 - 1, s, t, dp));
  }
  int tab(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
  {

    dp[0][0] = (s[0] == t[0]);

    for (int i = 1; i <= ind2; i++)
    {
      if (s[0] == t[i])
        dp[0][i] = 1;
      else
        dp[0][i] = dp[0][i - 1];
    }
    for (int i = 1; i <= ind1; i++)
    {
      if (s[i] == t[0])
        dp[i][0] = 1;
      else
        dp[i][0] = dp[i - 1][0];
    }

    for (int i = 1; i <= ind1; i++)
    {
      for (int j = 1; j <= ind2; j++)
      {
        if (s[i] == t[j])
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

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return tab(n - 1, m - 1, text1, text2, dp);
  }
  int minDistance(string word1, string word2)
  {
    return word1.size() - longestCommonSubsequence(word1, word2) + word2.size() - longestCommonSubsequence(word1, word2);
  }
};