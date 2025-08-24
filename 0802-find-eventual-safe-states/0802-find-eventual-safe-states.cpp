class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& v,
             vector<int>& path, vector<int>& check) {
        v[node] = 1;
        path[node] = 1;
        check[node] = 0;

        for (auto it : graph[node]) {
            if (!v[it]) {
                if (dfs(it, graph, v, path, check))
                    return true;
            } else if (path[it] == path[node]) {
                return true;
            }
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();

        vector<int> v(n, 0);
        vector<int> path(n, 0);
        vector<int> check(n, 0);

        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                dfs(i, graph, v, path, check);
            }
        }
        for (int i = 0; i < n; i++) {
            if (check[i]) {
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};