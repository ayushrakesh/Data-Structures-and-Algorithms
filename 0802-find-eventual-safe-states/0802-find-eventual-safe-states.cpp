class Solution {
public:
    bool dfs(int node, vector<int>& v, vector<int>& path,
             vector<vector<int>> &graph, vector<int> &check) {
        v[node] = 1;
        path[node] = 1;
        check[node]=0;

        for (auto it : graph[node]) {
            if (!v[it]) {
                if(dfs(it, v, path, graph,check)){
                    check[node]=1;
                    return true;
                }
            } else if (path[it]) {
                check[node]=1;
                return true;
            }
        }
        check[node]=0;
        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> v(graph.size(), 0);
        vector<int> path(graph.size(), 0);
        vector<int> res;
        vector<int> check(v.size(), 0);

        for (int i = 0; i < v.size(); i++) {
            if (!v[i]) {
                dfs(i, v, path, graph, check);
            }
        }
        for (int i = 0; i < check.size(); i++) {
            if (check[i]==0)
                res.push_back(i);
        }
        return res;
    }
};