class Solution {
public:
    int solve(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>&dp) {
        if (row == m - 1 && col == n - 1)
            return grid[m - 1][n - 1];
        if (row >= m || col >= n)
            return INT_MAX;
        if(dp[row][col] != -1)return dp[row][col];
        return dp[row][col] = min(solve(row + 1, col, m, n, grid, dp),
                   solve(row, col + 1, m, n, grid, dp)) +
               grid[row][col];
    }
    int tab(int m, int n, vector<vector<int>>& dp) {
        for (int i = 0; i <= n; i++)
            dp[m][i] = 0;
        for (int i = 0; i <= m; i++)
            dp[i][n] = 0;

        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0, 0, m, n, grid, dp);
    }
};