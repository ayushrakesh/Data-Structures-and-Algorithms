class Solution {
public:
    int solve(int row, int col, int n, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {
        if (row >= n)
            return 0;
        if (col > row)
            return INT_MAX;
        if (dp[row][col] != -1)
            return dp[row][col];
        return dp[row][col] = min(solve(row + 1, col, n, triangle, dp),
                                  solve(row + 1, col + 1, n, triangle, dp)) +
                              triangle[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, n, triangle, dp);
    }
};