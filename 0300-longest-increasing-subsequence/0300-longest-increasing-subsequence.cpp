class Solution {
public:

    int solve(int last, int ind, vector<int> nums, vector<vector<int>>& dp) {
    
        if (ind == nums.size()) return 0;
        if (dp[ind][last+1] != -1) return dp[ind][last+1];
        int take=0;
        if (last == -1 || nums[ind] > nums[last]) take=1+solve(ind, ind+1, nums, dp);
        int nottake=solve(last, ind+1, nums, dp);
        return dp[ind][last+1]=max(take, nottake);
    }
    int tab(vector<int> nums,vector<vector<int>> &dp){
        int n=nums.size();
        for(int i=0;i<=n;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int take=0;
                if(j==-1 || nums[i]>nums[j]){
                    take=1+dp[i+1][i+1];
                }
                dp[i][j+1]=max(take,dp[i+1][j+1]);
            }
        }
        return dp[0][-1+1];
    }    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1)); 
        // return solve(-1, 0, nums, dp);
        return tab(nums,dp);
    }
};