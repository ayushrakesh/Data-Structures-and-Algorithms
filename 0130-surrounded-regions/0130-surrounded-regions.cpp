class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<int>>& v,
             vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        v[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                board[nrow][ncol] == 'O' && !v[nrow][ncol]) {
                dfs(nrow, ncol, v, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> v(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (((i == 0 || i == (m - 1)) || (j == 0 || j == n - 1)) &&
                    board[i][j] == 'O') {
                    dfs(i, j, v, board);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 1) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};