class Solution {
public:
    bool solve(int row, int col, int ind, vector<vector<char>>& board,
               string word, vector<vector<int>>& v) {
        int m = board.size();
        int n = board[0].size();
        int l = word.size();

        if (ind >= l)
            return true;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        char c=board[row][col];
        board[row][col]='#';
        // v[row][col]=1;
        bool b = false;

        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                board[nrow][ncol] !='#' && board[nrow][ncol] == word[ind]) {
                b = solve(nrow, ncol, ind + 1, board, word, v);

                if (b)
                    return true;
            }
        }
        // v[row][col]=0;
        board[row][col]=c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    int ind = 1;
                    bool b = solve(i, j, ind, board, word, v);
                    if (b)
                        return true;
                }
            }
        }
        return false;
    }
};