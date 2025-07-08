class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums , vector<int>& path , int idx){
        if (path.size() >= 2) res.push_back(path);
        bitset<201> used;
        for (int i = idx, n = nums.size(); i < n; ++i) {
            if (!path.empty() && nums[i] < path.back()) continue;
            if (used.test(nums[i] + 100)) continue;
            used.set(nums[i] + 100);
            path.push_back(nums[i]);
            dfs(nums , path , i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        dfs(nums , path , 0);
        return res;
    }
};