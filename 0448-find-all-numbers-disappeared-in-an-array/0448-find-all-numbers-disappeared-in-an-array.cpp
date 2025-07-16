class Solution {
public:
    void better(vector<int>& nums, vector<int>& res) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());

        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end())
                res.push_back(i);
        }
    }
    void optimal(vector<int>& nums, vector<int>& res) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int corr = nums[i]-1;
            if (nums[i] != nums[corr])
                swap(nums[i], nums[corr]);
            else
                i++;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                res.push_back(i + 1);
        }
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        // better(nums, res);
        optimal(nums,res);
        return res;
    }
};