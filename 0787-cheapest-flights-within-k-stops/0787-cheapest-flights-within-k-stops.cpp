class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        int m = flights.size();
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < m; i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> res(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        res[src] = 0;

        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();

            for (auto it : adj[node]) {
                int nei = it.first;
                int wei = it.second;

                if (wei + dis < res[nei] && stops <= k) {
                    res[nei] = wei + dis;
                    q.push({stops + 1, {nei, res[nei]}});
                }
            }
        }
        if (res[dst] == INT_MAX)
            return -1;
        return res[dst];
    }
};