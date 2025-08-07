class Solution {
public:
    int countsetbits(int n) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i))
                cnt++;
        }
        return cnt;
    }
    int recur(int n,vector<int>&dp){
        if(n==0)return 0;
        if(n==1)return 1;

        if(dp[n] != -1)return dp[n];

        return dp[n] = recur(n >> 1,dp)+(n&1);
    }
    vector<int> countBits(int n) {
        vector<int> res(n + 1, -1);
        vector<int> dp(n+1,-1);

        for (int i = 0; i <= n; i++) {
            res[i] = recur(i,dp);
        }
        // return res;
        return res;
    }
};