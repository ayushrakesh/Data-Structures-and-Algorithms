class Solution {
public:
    void optimal(vector<int>&nums,vector<int>&res){
        int n=nums.size();

        int pre=1;
        for(int i=0;i<n;i++){
            res[i]=pre;
            pre=pre*nums[i];
        }
        int suf=1;
        for(int i=n-1;i>=0;i--){
            res[i]=res[i]*suf;
            suf=suf*nums[i];
        }
    }
    void better(vector<int>&nums,vector<int>&res){
          int n=nums.size();
        unordered_map<int,int> pre,suf;
        pre[-1]=1;
        suf[n]=1;
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]*nums[i];
        }
        for(int i=0;i<n;i++){
            res[i]=pre[i-1]*suf[i+1];
        }
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size(),0);
        // better(nums,res);
        optimal(nums,res);
        return res;
    }
};