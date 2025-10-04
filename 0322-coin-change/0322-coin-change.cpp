class Solution {
public:
    long long solve(int ind, int amount, vector<int>& coins,
                    vector<vector<int>>& dp) {
        int n = coins.size();

        if (ind == n - 1) {
            if (amount % coins[n - 1] == 0)
                return amount / coins[n - 1];
            return INT_MAX;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        long long nottake = solve(ind + 1, amount, coins, dp);
        long long take = INT_MAX;

        if (coins[ind] <= amount) {
            take = 1 + solve(ind, amount - coins[ind], coins, dp);
        }
        return dp[ind][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int res = ((int)solve(0, amount, coins, dp));
        return res == INT_MAX ? -1 : res;
    }
};