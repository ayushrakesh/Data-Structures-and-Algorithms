class Solution {
public:
    int optimal(vector<int>&nums){
        int n=nums.size();
        int xorr_total=0;
        for(int i=0;i<=n;i++)xorr_total^=i;
        int xorr_nums=0;
        for(int i=0;i<n;i++)xorr_nums^=nums[i];

        return xorr_total^xorr_nums;
    }
    int missingNumber(vector<int>& nums) {
        return optimal(nums);
    }
};