class Solution {
public:
    vector<vector<int>> better(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mp.find(-(nums[i] + nums[j])) == mp.end()) {
                    mp[nums[j]]++;
                } else {
                    vector<int> temp = {nums[i], nums[j], -(nums[i] + nums[j])};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
            mp.clear();
        }
        for (auto it : s) {
            res.push_back(it);
        }
        return res;
    }
    vector<vector<int>> optimal(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // return better(nums);
        return optimal(nums);
    }
};