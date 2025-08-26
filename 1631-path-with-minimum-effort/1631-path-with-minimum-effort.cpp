class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        dis[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nrow = row + i;
                    int ncol = col + j;

                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                        dis[nrow][ncol] >
                            (max(dis[row][col], abs(heights[row][col] -
                                                    heights[nrow][ncol])))) {
                        dis[nrow][ncol] =
                            max(dis[row][col],
                                abs(heights[row][col] - heights[nrow][ncol]));
                        pq.push({dis[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};