#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
  {
    if (j < 0)
      return i + 1;
    if (i < 0)
      return j + 1;

    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == t[j])
      return dp[i][j] = solve(i - 1, j - 1, s, t, dp);
    return dp[i][j] = 1 + min(solve(i, j - 1, s, t, dp), min(solve(i - 1, j, s, t, dp), solve(i - 1, j - 1, s, t, dp)));
  }
  int tab(string s, string t, vector<vector<int>> &dp)
  {
    int n = s.size();
    int m = t.size();

    for (int i = 0; i <= n; i++)
      dp[i][0] = i;
    for (int i = 0; i <= m; i++)
      dp[0][i] = i;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
      }
    }
    return dp[n][m];
  }
  int minDistance(string word1, string word2)
  {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return tab(word1, word2, dp);
  }
};