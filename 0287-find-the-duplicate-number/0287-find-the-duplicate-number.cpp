class Solution {
public:
    void cyclicsort(vector<int>&nums){
        int n=nums.size();
        int i=0;
        while(i<n){
            int corr=nums[i]-1;
            if(nums[i] != nums[corr])swap(nums[i],nums[corr]);
            else i++;
        }
    }
    int findDuplicate(vector<int>& nums) {
        cyclicsort(nums);
        return nums[nums.size()-1];
    }
};