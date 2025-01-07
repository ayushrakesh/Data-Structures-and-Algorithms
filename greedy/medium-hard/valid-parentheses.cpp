#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind, int cnt, string s, vector<vector<int>> &dp)
  {
    int n = s.length();
    if (ind == n)
    {
      if (cnt == 0)
        return 1;
      return 0;
    }
    if (cnt < 0)
      return 0;

    if (dp[ind][cnt] != -1)
      return dp[ind][cnt];

    if (s[ind] == '*')
      return dp[ind][cnt] = solve(ind + 1, cnt + 1, s, dp) ||
                            solve(ind + 1, cnt - 1, s, dp) ||
                            solve(ind + 1, cnt, s, dp);

    else if (s[ind] == '(')
      return dp[ind][cnt] = solve(ind + 1, cnt + 1, s, dp);

    return dp[ind][cnt] = solve(ind + 1, cnt - 1, s, dp);
  }

  void tab(string s, vector<vector<int>> &dp)
  {
    int n = s.length();

    dp[n][1] = 1;

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int cnt = 1; cnt <= n + 1; cnt++)
      {

        if (s[ind] == '*')
          dp[ind][cnt] = dp[ind + 1][cnt + 1] ||
                         dp[ind + 1][cnt - 1] || dp[ind + 1][cnt];

        else if (s[ind] == '(')
          dp[ind][cnt] = dp[ind + 1][cnt + 1];

        else
          dp[ind][cnt] = dp[ind + 1][cnt - 1];
      }
    }
  }

  bool checkValidString(string s)
  {
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 3, 0));
    // return solve(0, 0, s, dp);
    tab(s, dp);
    return dp[0][1];
  }
};