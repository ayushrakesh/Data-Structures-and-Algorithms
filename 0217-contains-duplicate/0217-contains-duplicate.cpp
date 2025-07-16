class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int i=1;

        while(i<n){
            if(nums[i]==nums[i-1])return true;
            i++;
        }
        return false;
    }
};