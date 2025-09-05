class Solution {
public:
    int better(vector<int>& height) {
        int n = height.size();
        int res = 0;
        vector<int> pre(n), suf(n);

        int a = height[0];
        for (int i = 0; i < n; i++) {
            pre[i] = max(a, height[i]);
            a = pre[i];
        }
        int b = height[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = max(b, height[i]);
            b = suf[i];
        }
        for (int i = 0; i < n; i++) {
            if (pre[i] > height[i] && height[i] < suf[i]) {
                res += (min(pre[i], suf[i]) - height[i]);
            }
        }
        return res;
    }
    int optimal(vector<int>&height){
        int n=height.size();
        int i=0,j=n-1;
        int lmax=0,rmax=0;
        int res=0;
        while(i<=j){
            lmax=max(lmax,height[i]);
            rmax=max(rmax,height[j]);

            if(lmax<=rmax){
                res+=lmax-height[i];
                i++;
            }
            else{
                res+=rmax-height[j];
                j--;
            }
        }
        return res;
    }
    int trap(vector<int>& height) {
        // return better(height);
        return optimal(height);
    }
};