class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int bp=-1;

        for(int i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                bp=i-1;
                break;
            }
        }
        if(bp==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int ind=n-1;
        while(ind>bp){
            if(nums[ind]>nums[bp]){
                swap(nums[ind],nums[bp]);
                break;
            }
            ind--;
        }
        reverse(nums.begin()+bp+1,nums.end());
        
    }
};