class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& v,
             vector<int>& colors) {
        queue<int> q;
        q.push(node);
        v[node] = 1;
        colors[node] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto it : graph[curr]) {
                if (!v[it]) {
                    v[it] = 1;
                    colors[it] = !colors[curr];
                    q.push(it);
                } else if (colors[it] == colors[curr])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v(n, 0);
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                if (!bfs(i, graph, v, colors))
                    return false;
            }
        }
        return true;
    }
};