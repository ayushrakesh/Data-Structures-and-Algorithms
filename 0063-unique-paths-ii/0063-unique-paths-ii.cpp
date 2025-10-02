class Solution {
public:
     int solve(int row, int col, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp) {
        if (row == m - 1 && col == n - 1)
            return 1;
        if (row >= m || col >= n)
            return 0;
        if(grid[row][col]==1)return 0;

        if(dp[row][col] != -1)return dp[row][col];
        return dp[row][col] =  solve(row + 1, col, m, n, grid, dp) +
                              solve(row, col + 1, m, n, grid, dp);
    }
    int tab(int m, int n, vector<vector<int>>& dp) {
        for (int i = 0; i <= n; i++)
            dp[m][i] = 0;
        for (int i = 0; i <= m; i++)
            dp[i][n] = 0;

        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if(i==m-1 && j==n-1)continue;
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])return 0;
        return solve(0,0,m,n,obstacleGrid, dp);
    }
};