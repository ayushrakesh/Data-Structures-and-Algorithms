class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<int>& v,
               vector<vector<int>>& res) {
        if (ind >= nums.size()) {
            res.push_back(v);
            return;
        }

        v.push_back(nums[ind]);
        solve(ind + 1, nums, v, res);
        v.pop_back();

        solve(ind + 1, nums, v, res);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        solve(0, nums, v, res);
        return res;
    }
};