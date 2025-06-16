class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    res = max(res, nums[j] - nums[i]);
                }
            }
        }
        return res?res:-1;
    }
};