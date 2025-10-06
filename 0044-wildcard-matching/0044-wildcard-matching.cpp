class Solution {
public:
    bool solve(int i, int j, string s, string t, vector<vector<int>>& dp) {
        int n = s.size(), m = t.size();
        if (i >= n && j >= m)
            return true;
        if (i >= n && j < m)
            return false;
        if (i < n && j >= m) {
            for (int k = i; k < n; k++) {
                if (s[k] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j] || s[i] == '?')
            return dp[i][j] = solve(i + 1, j + 1, s, t, dp);
        if (s[i] == '*')
            return dp[i][j] = solve(i + 1, j, s, t, dp) ||
                              solve(i + 1, j + 1, s, t, dp) ||
                              solve(i, j + 1, s, t, dp);
        return dp[i][j] = false;
    }
    int tab(string s,string t,vector<vector<int>>&dp){
        int n=s.size();
        int m=t.size();
        
        dp[n][m]=1;
        for(int i=0;i<m;i++)dp[n][i]=0;
        for(int i=0;i<n;i++){
            for(int k=i;k<n;k++){
                if(s[k]!='*'){}
            }
        }
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, p, s, dp);
    }
};