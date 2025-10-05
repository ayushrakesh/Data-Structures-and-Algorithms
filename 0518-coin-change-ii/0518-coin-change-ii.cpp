class Solution {
public:
    int solve(int ind, vector<int>& coins, int target, vector<vector<int>> &dp) {
        int n = coins.size();
        if (ind >= n) {
            return target == 0;
        }
        if(dp[ind][target] != -1)return dp[ind][target];

        int nottake = solve(ind + 1, coins, target, dp);
        int take = 0;
        if (coins[ind] <= target)
            take =  solve(ind, coins, target - coins[ind], dp);

        return dp[ind][target] = nottake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(0, coins, amount, dp);
    }
};