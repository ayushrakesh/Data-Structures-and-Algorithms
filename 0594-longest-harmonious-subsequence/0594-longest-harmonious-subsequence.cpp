class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int len =0;
        for(int i:nums){
            mp[i]++;
        }
        for(auto it:mp){
            // check for the next greater element and add their count sum
            if(mp.find(it.first+1)!= mp.end()){
                len = max(len, it.second + mp[it.first+1]);
            }
        }
        return len;
    }
};