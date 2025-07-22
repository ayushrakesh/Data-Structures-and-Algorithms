class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[nums[i]]++;

        int res = 1;
        for (int i = 0; i < n; i++) {
            if (m.find(nums[i] - 1) == m.end()) {
                int cnt = 1;
                int curr = nums[i];
                while (m.find(curr + 1) != m.end()) {
                    cnt++;
                    curr++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};