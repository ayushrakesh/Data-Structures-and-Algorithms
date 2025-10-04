class Solution {
public:
    bool solve(int ind, int n, vector<int>& nums, int target,
               vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (ind == n - 1)
            return nums[ind] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool nottake = solve(ind + 1, n, nums, target, dp);
        bool take = false;
        if (nums[ind] <= target)
            take = solve(ind + 1, n, nums, target - nums[ind], dp);
        return dp[ind][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;

        int target = sum / 2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(0, n, nums, target, dp);
    }
};