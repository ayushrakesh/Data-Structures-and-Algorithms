class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int p=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                p=i;
                break;
            }
        }
        if(p==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=n-1;
        while(j>=0 && j>p && nums[j]<= nums[p]){
            j--;
        }
        swap(nums[j],nums[p]);
        sort(nums.begin()+p+1,nums.end());
        return;
    }
};