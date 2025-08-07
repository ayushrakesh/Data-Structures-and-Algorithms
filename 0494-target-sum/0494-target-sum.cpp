class Solution {
public:
    int recur(vector<int>& nums, int target, int curr, int ind) {
        int n = nums.size();
        if (ind >= n) {
            return curr == target ? 1 : 0;
        }

        int plus = recur(nums, target, curr + nums[ind], ind + 1);
        int minus = recur(nums, target, curr - nums[ind], ind + 1);

        return plus + minus;
    }
    int memo(vector<int>& nums, int target, int curr, int ind,
             vector<vector<int>>& dp) {
        int n = nums.size();
        if (ind >= n) {
            return curr == target ? 1 : 0;
        }

        if (dp[ind][curr + 1000] != -1)
            return dp[ind][curr + 1000];

        int plus = memo(nums, target, curr + nums[ind], ind + 1, dp);
        int minus = memo(nums, target, curr - nums[ind], ind + 1, dp);

        return dp[ind][curr + 1000] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return memo(nums, target, 0, 0, dp);
    }
};