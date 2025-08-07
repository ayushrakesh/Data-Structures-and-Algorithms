class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(ind>=n)return 0;

        if(dp[ind] != -1)return dp[ind];

        return dp[ind] = max(solve(ind+1,nums,dp),solve(ind+2,nums,dp)+nums[ind]);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};