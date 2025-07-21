class Solution {
public:
    void cyclicSort(vector<int>& v) {
        int i = 0;
        while (i < v.size()) {
            int corr = v[i] - 1;

            if (v[i] != v[corr])
                swap(v[i], v[corr]);
            else
                i++;
        }
    }
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        cyclicSort(nums);
        vector<int> res;
        
        for(int i=0;i<n;i++){
            if(nums[i] != (i+1))res.push_back(nums[i]);
        }
        return res;
    }
};