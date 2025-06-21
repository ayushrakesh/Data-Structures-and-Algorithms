class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int mx=nums[0];
        int smx=INT_MIN;
        int x=0,y=0;
        int tmx=INT_MIN;
        for(auto u: nums){
            mx=max(u,mx);
        }
        for(auto u: nums){
            if(u>smx&&u<mx){
                smx=u;
            }
        }
        if(smx==INT_MIN) return mx;
        for(auto u: nums){
            if(u>tmx&&u<smx){
                tmx=u;
            }
        }
        for(auto u:nums){
            if(u==tmx) return tmx;
        }
        return mx;
    }
};