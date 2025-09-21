class Solution {
public:
    bool solve(int ind, vector<int>& stones, unordered_map<int,int>& s, int prev, vector<vector<int>>& dp) {
        int n = stones.size();
        if(n==1)return true;
        if (ind == n - 1)
            return true;
        if(ind > n-1)return false;

        if(dp[ind][prev] != -1)return dp[ind][prev];

        bool a = false, b = false, c = false;
        if (s.find(stones[ind] + prev) != s.end() && s[stones[ind] + prev] != ind) {
            a = solve(s[stones[ind] + prev], stones, s, prev, dp);
        }
        if (s.find(stones[ind] + prev - 1) != s.end() && s[stones[ind] + prev - 1] != ind) {
            b = solve(s[stones[ind] + prev - 1], stones, s, prev - 1, dp);
        }
        if (s.find(stones[ind] + prev + 1) != s.end() && s[stones[ind] + prev + 1] != ind) {
            c = solve(s[stones[ind] + prev + 1], stones, s, prev + 1, dp);
        }
        return dp[ind][prev] = a || b || c;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,int> s;
        for(int i=0;i<n;i++){
            s[stones[i]]=i;
        }
        if (stones[1] != 1)
            return false;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(1, stones, s, 1,dp);
    }
};