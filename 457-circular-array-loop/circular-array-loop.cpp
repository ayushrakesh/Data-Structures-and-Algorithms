class Solution {
public:
    int nextIndex(vector<int>&nums,int curr,bool direction){
        int n=nums.size();

        bool newdire=nums[curr] >= 0;
        if(newdire!=direction)return -1;

        int next=(curr+nums[curr])%n;
        if(next<0)next+=n;
        
        if(next==curr)return -1;
        return next;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            bool direction=nums[i]>=0;

            int slow=i,fast=i;

            while(true){
                slow=nextIndex(nums,slow,direction);
                fast=nextIndex(nums,fast,direction);

                if(fast!=-1){
                    fast=nextIndex(nums,fast,direction);
                }

                if(slow==-1 || fast==-1 || slow==fast){
                    break;
                }
            }
            if(slow != -1 && fast!=-1 && slow==fast)return true;
        }
        return false;
    }
};