class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    adj[i][j] = 0;
            }
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][via] != INT_MAX && adj[via][j] != INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                    }
                }
            }
        }
        int res = -1;
        int mincities = n;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && adj[i][j] <= distanceThreshold)
                    cnt++;
            }
            if (mincities > cnt || (mincities==cnt && (i>res))) {
                mincities = cnt;
                res = i;
            }
        }
        return res;
    }
};