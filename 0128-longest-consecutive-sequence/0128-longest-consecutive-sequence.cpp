class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        // if(!n)return 0;
        // unordered_set<int> m(nums.begin(),nums.end());
        // int res = 1;
        
        // for (int i = 0; i < n; i++) {
        //     if (m.find(nums[i] - 1) == m.end()) {
        //         int cnt = 1;
        //         int curr = nums[i];
        //         while (m.find(curr + 1) != m.end()) {
        //             cnt++;
        //             curr++;
        //         }
        //         res = max(res, cnt);
        //     }
        // }
        // return res;

        sort(nums.begin(),nums.end());
        int res=0;
        int curr=1;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            if(i>0 && nums[i] == nums[i-1]+1){
                curr++;
            }
            else{
                res=max(res,curr);
                curr=1;
            }
        }
        return max(res,curr);
    }
};