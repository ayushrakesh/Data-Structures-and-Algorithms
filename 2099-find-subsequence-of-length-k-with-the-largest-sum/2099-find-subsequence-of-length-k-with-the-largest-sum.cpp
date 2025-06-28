class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;

        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        priority_queue<int, vector<int>, greater<int>> temp;
        while (k > 0) {
            temp.push(pq.top().second);
            pq.pop();
            k--;
        }

        while (!temp.empty()) {
            res.push_back(nums[temp.top()]);
            temp.pop();
        }

        return res;
    }
};