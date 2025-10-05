class Solution {
public:
    int tab(string s, string t, vector<vector<int>>& dp) {
        int n = s.size(), m = t.size();
        for (int i = 0; i <= m; i++)
            dp[n][i] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][m] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        tab(str1, str2, dp);
        string res = "";

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                res.push_back(str1[i]);
                i++;
                j++;
            } else {
                if (dp[i + 1][j] >= dp[i][j + 1]) {
                    res.push_back(str1[i]);
                    i++;
                } else {
                    res.push_back(str2[j]);
                    j++;
                }
            }
        }
        while (i < n)
            res.push_back(str1[i]), i++;
        while (j < m)
            res.push_back(str2[j]), j++;
        return res;
    }
};