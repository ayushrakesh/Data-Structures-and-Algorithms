class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0, 0});

        vector<long long> ways(n, 0);
        vector<long long> dis(n, LONG_MAX);
        ways[0] = 1;
        dis[0] = 0;
        int mod  = (int)(1e9+7);

        while (!pq.empty()) {
            int node = pq.top().second;
            long long cost = pq.top().first;
            pq.pop();

            for (auto it : adj[node]) {
                if (dis[it.first] > (cost + it.second)) {
                    dis[it.first] = cost + it.second;
                    ways[it.first] = ways[node];
                    pq.push({dis[it.first], it.first});
                } else if (dis[it.first] == (cost + it.second)) {
                    ways[it.first] =(ways[it.first] + ways[node])%mod;
                }
            }
        }
        return ways[n - 1]%mod;
    }
};