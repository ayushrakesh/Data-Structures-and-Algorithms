class Solution {
public:
    int brute(vector<int>&nums){
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[0] > nums[1])return 0;
            }
            else if(i==n-1){
                if(nums[n-1] > nums[n-2])return n-1;
            }
            else{
                if(nums[i] > nums[i+1] && nums[i]>nums[i-1])return i;
            }
        }
        return -1;
    }
    int optimal(vector<int>&nums){
        int n=nums.size();
        if(n==2){
            return nums[0]>nums[1]?0:1;
        }
        if(nums[0]>nums[1])return 0;
        if(nums[n-1] > nums[n-2])return n-1;
        
        int low=1,high=n-2;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] > nums[mid+1] && nums[mid]>nums[mid-1])return mid;
            
            if(nums[mid] > nums[mid-1])low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
        // return brute(nums);
        return optimal(nums);
    }
};