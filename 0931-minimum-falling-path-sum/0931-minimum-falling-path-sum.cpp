class Solution {
public:
    int solve(int row, int col, int n, vector<vector<int>>& mat,
              vector<vector<int>>& dp) {
        if (row >= n)
            return 0;
        if (col < 0 || col >= n)
            return INT_MAX;
        if (dp[row][col] != -1)
            return dp[row][col];
        return dp[row][col] = min(solve(row + 1, col - 1, n, mat, dp),
                                  min(solve(row + 1, col, n, mat, dp),
                                      solve(row + 1, col + 1, n, mat, dp))) +
                              mat[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        for (int i = 0; i < n; i++) {
            res = min(res, solve(0, i, n, matrix, dp));
        }
        return res;
    }
};