class Solution {
public:
    int optimal(vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        vector<int> u, v;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n, -1);

        for (int i = 0; i < n; i++) {
            if (i != 0)
                u.push_back(nums[i]);
            if (i != (n - 1))
                v.push_back(nums[i]);
        }
        int a = optimal(u, dp);
        dp.resize(n, -1);
        int b = optimal(v, dp);
        return max(a,b);
    }
};