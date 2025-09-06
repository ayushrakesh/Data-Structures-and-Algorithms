class Solution {
public:
    vector<int> brute(vector<int>&nums, int k){
        int n=nums.size();
        vector<int> res;
        int maxi=nums[0];
        
        for(int i=0;i<n-k+1;i++){
            int maxi=nums[i];
            for(int j=i;j<i+k;j++){
                maxi=max(maxi,nums[j]);
            }
            res.push_back(maxi);
        }
        return res;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        
        return brute(nums,k);
    }
};