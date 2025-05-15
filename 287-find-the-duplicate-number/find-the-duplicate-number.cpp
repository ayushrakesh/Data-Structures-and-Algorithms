class Solution {
public:
    void cyclicSort(vector<int>& v) {
        int i = 0;
        while (i < v.size()) {
            int corr = v[i]-1;

            if (v[i] != v[corr])
                swap(v[i], v[corr]);
            else
                i++;
        }
    }
    int slowAndFast(vector<int>&nums){
        int n=nums.size();

        int slow=nums[0];
        int fast=nums[0];

        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];

            if(slow==fast)break;
        }

        slow=nums[0];

        while(slow != fast){
            slow=nums[slow];
            fast=nums[fast];
        }

        return fast;
    }
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        cyclicSort(nums);

        return slowAndFast(nums);
    }
};