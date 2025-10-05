class Solution {
public:
    int solve(int i, int j, string s, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = solve(i + 1, j - 1, s, dp);
        return dp[i][j] =
                   1 + min(solve(i + 1, j, s, dp), solve(i, j - 1, s, dp));
    }
    int tab(string s, vector<vector<int>>& dp) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j)
                    dp[i][j] = 0;
                if (i == j)
                    dp[i][j] = 0;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i < j) {
                    if (s[i] == s[j])
                        dp[i][j] = dp[i + 1][j - 1];
                    else
                        dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, n - 1, s, dp);
        return tab(s, dp);
    }
};