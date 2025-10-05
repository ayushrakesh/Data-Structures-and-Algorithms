class Solution {
public:
    int solve(int ind, vector<int>& coins, int target,
              vector<vector<int>>& dp) {
        int n = coins.size();
        if (ind >= n) {
            return target == 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];

        int nottake = solve(ind + 1, coins, target, dp);
        int take = 0;
        if (coins[ind] <= target)
            take = solve(ind, coins, target - coins[ind], dp);

        return dp[ind][target] = nottake + take;
    }
    int tab(vector<int>& coins, int amount, vector<vector<int>>& dp) {
        int n = coins.size();

        for (int i = 0; i <= amount; i++) {
            if (i == 0)
                dp[n][0] = 1;
            else
                dp[n][i] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                long long nottake = dp[i + 1][j];
                long long take = 0;
                if (coins[i] <= j)
                    take = dp[i][j - coins[i]];
                dp[i][j] = (int)take + nottake;
            }
        }
        return dp[0][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        // return solve(0, coins, amount, dp);
        return tab(coins, amount, dp);
    }
};