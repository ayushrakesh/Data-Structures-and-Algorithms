class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return INT_MIN;
        if (i == m - 1) {
            if (j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int temp = INT_MIN;
        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {
                temp = max(temp, solve(i + 1, j1 + k, j2 + l, grid, dp));
            }
        }
        if (j1 == j2)
            return dp[i][j1][j2] = temp + grid[i][j1];
        return dp[i][j1][j2] = temp + grid[i][j1] + grid[i][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, n - 1, grid, dp);
    }
};