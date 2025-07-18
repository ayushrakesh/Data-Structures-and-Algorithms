class Solution {
public:
    void brute(vector<int>& nums, vector<int>& res) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i] * nums[i]);
        }
        sort(res.begin(), res.end());
    }
    void better(vector<int>& nums, vector<int>& res) {
        const int n = nums.size();
        int i = 0, j = n - 1;

        int arr[n];
        int ind=n-1;

        while (i <= j) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];

            if (a >= b) {
                arr[ind] = a;
                i++;
            } else {
                arr[ind] = b;
                j--;
            }
            ind--;
        }
        for (int i = 0; i < n; i++) {
            res.push_back(arr[i]);
        }
    }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        // brute(nums,res);
        better(nums, res);
        return res;
    }
};