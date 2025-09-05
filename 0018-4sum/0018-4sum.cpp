class Solution {
public:
    vector<vector<int>> brute(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k],
                                                nums[l]};
                            sort(temp.begin(), temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> res(s.begin(), s.end());
        // return res(s.begin(),s.end());
        return res;
    }
    vector<vector<int>> better(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_map<long long, int> mp;
                for (int k = j + 1; k < n; k++) {
                    if (mp.find(target - (nums[i] + nums[j] + nums[k])) !=
                        mp.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k],
                                            target - nums[i] - nums[j] -
                                                nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                    mp[nums[k]]++;
                }
            }
        }
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
    vector<vector<int>> optimal(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if(j != i+1 && nums[j]==nums[j-1])continue;
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // return brute(nums, target);
        // return better(nums, target);
        return optimal(nums,target);
    }
};