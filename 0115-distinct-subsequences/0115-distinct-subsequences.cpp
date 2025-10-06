class Solution {
public:
    int solve(int i, int j, string s, string t, vector<vector<int>>& dp) {
        int n = s.size(), m = t.size();

        if (j >= m)
            return 1;
        if (i >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = solve(i + 1, j + 1, s, t, dp) +
                              solve(i + 1, j, s, t, dp);
        return dp[i][j] = solve(i + 1, j, s, t, dp);
    }
    int tab(string s, string t, vector<vector<unsigned long long>>& dp) {
        int n = s.size(), m = t.size();

        for (int i = 0; i <= m; i++)
            dp[n][i] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][m] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (s[i] == t[j])
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                else
                    dp[i][j] = dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, -1));
        // return solve(0, 0, s, t, dp);
        return tab(s, t, dp);
    }
};