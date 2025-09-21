class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int res = INT_MIN;

        int i = 0;
        while (i < n) {
            if (i + 2 < n) {
                res = max(res, abs(stones[i] - stones[i + 2]));
            }
            i += 2;
        }

        if (i == n) {
            i = n - 1;
        } else {
            i = n - 2;
        }
        res = max(res, abs(stones[n - 2] - stones[n - 1]));

        while (i >= 0) {
            if (i - 2 >= 0) {
                res = max(res, abs(stones[i] - stones[i - 2]));
            }
            i -= 2;
        }
        if (i == -1) {
            res = max(res, abs(stones[0] - stones[1]));
        }
        return res;
    }
};