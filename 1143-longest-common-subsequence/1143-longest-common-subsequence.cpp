class Solution {
public:
    int solve(int ind1, int ind2, string s, string t, vector<vector<int>>& dp) {
        int n = s.size(), m = t.size();
        if (ind1 >= n || ind2 >= m)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s[ind1] == t[ind2])
            return dp[ind1][ind2] = 1 + solve(ind1 + 1, ind2 + 1, s, t, dp);
        return dp[ind1][ind2] = max(solve(ind1 + 1, ind2, s, t, dp),
                                    solve(ind1, ind2 + 1, s, t, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, text1, text2, dp);
    }
};