class Solution {
public:
    int solve(int ind, int curr, vector<int>& nums, int target, int& res,vector<vector<int>>&dp) {
        if (ind >= nums.size()) {
            if (curr == target) return 1;
            return 0;
        }

        if(dp[ind][curr+1000] != 0) return dp[ind][curr+1000]; 

        dp[ind][curr+1000]+= solve(ind + 1, curr + nums[ind], nums, target, res,dp);
        dp[ind][curr+1000]+= solve(ind + 1, curr - nums[ind], nums, target, res,dp);
        
        return dp[ind][curr+1000];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        vector<vector<int>> dp(nums.size(),vector<int>(2001,0));
        return solve(0, 0, nums, target, res,dp);
    }
};