class Solution {
public:
    void solve(int ind, int curr, vector<int>& nums, int target, int& res) {
        if (ind >= nums.size()) {
            if (curr == target)
                res++;
            return;
        }
        solve(ind + 1, curr + nums[ind], nums, target, res);
        solve(ind + 1, curr - nums[ind], nums, target, res);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        solve(0, 0, nums, target, res);
        return res;
    }
};