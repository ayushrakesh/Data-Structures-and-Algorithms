class Solution {
public:
    int solve(int ind, vector<int>& coins, int target) {
        int n = coins.size();
        if (ind >= n) {
            return target == 0;
        }

        int nottake = solve(ind + 1, coins, target);
        int take = 0;
        if (coins[ind] <= target)
            take =  solve(ind, coins, target - coins[ind]);

        return nottake + take;
    }
    int change(int amount, vector<int>& coins) {
        return solve(0, coins, amount);
    }
};