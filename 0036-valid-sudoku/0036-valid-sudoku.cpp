class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;

                for (int k = 0; k < 9; k++) {
                    if (i != k && board[k][j] != '.' && board[k][j] == c)
                        return false;
                }
                for (int k = 0; k < 9; k++) {
                    if (k != j && board[i][k] != '.' && board[i][k] == c)
                        return false;
                }
                int startRow = (i / 3) * 3;
                int startCol = (j / 3) * 3;
                for (int r = startRow; r < startRow + 3; r++) {
                    for (int col = startCol; col < startCol + 3; col++) {
                        if ((r != i || col != j) && board[r][col] == c)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};