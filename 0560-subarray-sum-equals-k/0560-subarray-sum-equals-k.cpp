class Solution {
public:
    int optimal(vector<int>&nums,int k){
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0]=1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                res+=mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
    int brute(vector<int>&nums,int k){
        int n=nums.size();
        int res=0;
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k)res++;
            }
        }
        return res;
    }
    int subarraySum(vector<int>& nums, int k) {
        // return optimal(nums,k);
        return brute(nums,k);
    }
};