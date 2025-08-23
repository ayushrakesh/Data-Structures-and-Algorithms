class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> v(m, vector<int>(n, 0));
        int res = 0;
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    v[i][j] = 2;
                }
            }
        }

        while (!q.empty()) {
            int a = q.front().first.first;
            int b = q.front().first.second;

            int t = q.front().second;
            q.pop();

            vector<int> row = {-1, 0, 1, 0};
            vector<int> col = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = a + row[i];
                int ncol = b + col[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1 && v[nrow][ncol]==0) {
                    q.push({{nrow, ncol}, t + 1});
                    res = max(res, t + 1);
                    v[nrow][ncol] = 2;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(v[i][j]!=2  && grid[i][j]==1 )return -1;
            }
        }
        return res;
    }
};