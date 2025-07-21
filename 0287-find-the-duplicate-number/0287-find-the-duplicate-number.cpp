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
    int optimal(vector<int>&nums){
        int n=nums.size();
        
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow != fast);

        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
    int better(vector<int>&nums){
        int n=nums.size();
        int low=1,high=n;

        while(low<high){
            int mid=low+((high-low)/2);
            int cnt=0;
            for(int num:nums){
                if(num <= mid)cnt++;
            }

            if(cnt<=mid)high=mid;
            else low=mid+1;
        }
        return low;
    }
    int findDuplicate(vector<int>& nums) {
        // cyclicsort(nums);
        // return optimal(nums);
        // return better(nums);
        return optimal(nums);
    }
};