class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, src}});
        dis[src] = 0;

        while (!pq.empty()) {
            int node = pq.top().second.second;
            int stops = pq.top().first;
            int d = pq.top().second.first;
            pq.pop();
            if (stops <= k) {
                // cout<<node<<" "<<stops<<endl;

                for (auto it : adj[node]) {
                    int nei = it.first;
                    int wt = it.second;

                    if (dis[nei] > (d + wt)) {
                        dis[nei] = d + wt;
                        pq.push({stops + 1, {dis[nei], nei}});
                    }
                }
            }
        }
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};