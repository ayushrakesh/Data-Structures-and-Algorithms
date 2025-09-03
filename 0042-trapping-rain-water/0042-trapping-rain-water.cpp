class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        vector<int> pre(n), suf(n);

        int a = height[0];
        for (int i = 0; i < n; i++) {
            pre[i] = max(a, height[i]);
            a=pre[i];
        }
        int b = height[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = max(b, height[i]);
            b=suf[i];
        }
        for (int i = 0; i < n; i++) {
            if (pre[i] > height[i] && height[i] < suf[i]) {
                res += (min(pre[i], suf[i]) - height[i]);
            }
        }
        return res;
    }
};