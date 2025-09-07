class Solution {
public:
    int solve(int ind, int last, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind >= nums.size())
            return 0;

        if (dp[ind][last + 1] != -1)
            return dp[ind][last + 1];
        int take = 0;
        if (last == -1 || nums[ind] > nums[last]) {
            take = solve(ind + 1, ind, nums, dp) + 1;
        }

        int nottake = solve(ind + 1, last, nums, dp);
        return dp[ind][last + 1] = max(take, nottake);
    }
    int tab(vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();

        for (int i = -1; i < n; i++) {
            dp[n][i+1] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = -1; j < i; j++) {
                int take = 0;
                if (j == -1 || nums[i] > nums[j]) {
                    take = dp[i + 1][i+1] + 1;
                }
                int nottake = dp[i + 1][j+1];
                dp[i][j+1] = max(take, nottake);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solve(0, -1, nums, dp)
        return tab(nums,dp);
    }
};