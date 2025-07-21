class Solution {
public:
    int brute(vector<int>&nums){
        int n=nums.size();

        for(int i = 0;i<n;i++){
            int ele =nums[i];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(nums[j]==ele){
                    cnt++;
                }
            }
            if(cnt > floor(n/2.00))return ele;
        }
        return -1;
    }
    int better(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto it : mp) {
            if (it.second > (n / 2)) {
                return it.first;
            }
        }
        return -1;
    }
    int optimal(vector<int>& nums) {
        int n = nums.size();
        int ele;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                ele = nums[i];
                count++;
            } else if (nums[i] == ele)
                count++;
            else
                count--;
        }
        return ele;
    }
    int majorityElement(vector<int>& nums) {
        return brute(nums);
        // return optimal(nums);
    }
};