class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& v,
             vector<int>& path) {
        v[node] = 1;
        path[node] = 1;

        for (auto it : adj[node]) {
            if (!v[it]) {
                if (dfs(it, adj, v, path))
                    return true;
            } else if (path[it] == path[node])
                return true;
        }

        path[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        vector<int> v(n, 0);
        vector<int> path(n, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                if (dfs(i, adj, v, path))
                    return false;
            }
        }
        return true;
    }
};