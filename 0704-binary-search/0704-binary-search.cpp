class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int res=-1;
        int i=0,j=n-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid] < target)i=mid+1;
            else j=mid-1;
        }
        return res;
    }
};