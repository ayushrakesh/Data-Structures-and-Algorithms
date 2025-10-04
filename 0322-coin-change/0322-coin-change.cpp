class Solution {
public:
    int solve(int ind , int target, vector<int> arr, vector<vector<int>>& dp) {
        int n=arr.size();
        if (ind == 0) {
            if (target % arr[ind] == 0) return target/arr[ind];
            else return 1e8;
        }
        
        if (dp[ind][target]!=-1) return dp[ind][target];
        
        int pick=1e8;
        if (target >= arr[ind]) {
            pick = 1 + solve(ind, target-arr[ind], arr, dp);
        }
        int notpick = solve(ind-1, target, arr, dp);
        
        return dp[ind][target] = min(pick , notpick);
        // return min(pick , notpick);
    }
    int tab(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
        int n=arr.size();
        for(int i=0;i<=target;i++){
            if(i % arr[0]==0){
                dp[0][i]=i/arr[0];
            }
            else dp[0][i]=1e8;
        }
        
        for(int i=1;i<=ind;i++){
            for(int j=0;j<=target;j++){
                if(arr[i]<=j){
                    dp[i][j]=min(dp[i-1][j], 1 + dp[i][j-arr[i]]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[ind][target];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int res = tab(n-1, amount, coins, dp);
        if (res == 1e8) return -1;
        return res;
    }
};