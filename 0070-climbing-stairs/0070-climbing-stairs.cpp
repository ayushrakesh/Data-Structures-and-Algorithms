class Solution {
public:
    int solve(int n) {
        if (n == 0 || n == 1)
            return 1;
        return solve(n - 1) + solve(n - 2);
    }
    int memo(int n, vector<int>& dp) {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = memo(n - 1, dp) + memo(n - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        // return solve(n);
        return memo(n, dp);
    }
};