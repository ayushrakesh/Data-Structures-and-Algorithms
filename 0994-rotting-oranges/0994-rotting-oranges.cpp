class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));
        queue<pair<int, pair<int,int>>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({0,{i, j}});
                    v[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int t=q.front().first;
            res=max(res,t);

            q.pop();

            vector<int> nr = {-1, 0, 1, 0};
            vector<int> nc = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = row + nr[i];
                int ncol = col + nc[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    !v[nrow][ncol] && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol]=2;
                    q.push({t+1,{nrow, ncol}});
                    v[nrow][ncol] = 1;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return res;
    }
};