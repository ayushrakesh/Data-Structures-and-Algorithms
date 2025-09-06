class Solution {
public:
    string brute(string s) {
        int n = s.size();
        string res = "";

        for (int i = 0; i < n; i++) {
            int low = i, high = i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
            }
            low++;
            high--;
            if (high - low + 1 > (int)res.size()) {
                res = s.substr(low, high - low + 1);
            }

            low = i, high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
            }
            low++;
            high--;
            if (high - low + 1 > (int)res.size()) {
                res = s.substr(low, high - low + 1);
            }
        }
        return res;
    }
    string better(string s){
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxlen=1;
        int start=0;

        for(int i=0;i<n;i++)dp[i][i]=1;

        for(int len=2;len<=n;len++){
            for(int i=0;i<n;i++){
                int j=i+len-1;

                if(j<n && s[i]==s[j]){
                    if(dp[i+1][j-1]==1 || len==2){
                        dp[i][j]=1;
                        if(maxlen < len){
                            maxlen=len;
                            start=i;
                        }
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
    string longestPalindrome(string s) {
        // return optimal(s);
        return better(s);
    }
};
