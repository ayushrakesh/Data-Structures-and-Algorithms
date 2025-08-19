class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res=0;

        int n=nums.size();
        int i=0;

        while(i<n){
            int cnt=0;
            while(i<n && nums[i]==0){
                i++;
                cnt++;
            }
            res+=((cnt)*(cnt+1))/2;
            i++;
        }
        return res;
    }
};