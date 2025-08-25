class Solution {
public:
    vector<int> solveBFS(int V, vector<int> adj[]) {
        vector<int> indeg(V, 0);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                indeg[adj[i][j]]++;
            }
        }

        queue<int> q;
        vector<int> res;

        for (int i = 0; i < indeg.size(); i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for (auto it : adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        return res;
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        return solveBFS(V, adj);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[V];

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> res = topoSort(V, adj);
        if (res.size() != V)
            return {};
        return res;
    }
};