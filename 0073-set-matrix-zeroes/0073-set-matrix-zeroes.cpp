class Solution {
public:
    void better(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.at(0).size();

        vector<int> row(n);
        vector<int> col(m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                /* code */
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void optimal(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.at(0).size();
        bool fr=false,fc=false;

        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0)
                fr = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                fc = true;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[0][i] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (fr) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        if (fc) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        //    better(matrix);
        optimal(matrix);
    }
};