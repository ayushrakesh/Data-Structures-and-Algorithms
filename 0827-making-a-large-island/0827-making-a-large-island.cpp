class DisJointSet {
public:
    vector<int> parent, size;
    DisJointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionBySize(int u, int v) {
        int up_u = find(u);
        int up_v = find(v);
        if (up_u == up_v)
            return;

        if (size[up_u] <= size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        } else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSet ds(n*n);
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int u = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int nrow = i + dr[k];
                        int ncol = j + dc[k];
                        int v = nrow * n + ncol;
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                            grid[nrow][ncol] && ds.find(u) != ds.find(v)) {
                            ds.unionBySize(u, v);
                        }
                    }
                }
            }
        }
        int res=0;
        bool b=false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    b=true;
                    int cnt=1;
                    set<int> s;
                    for (int k = 0; k < 4; k++) {
                        int nrow = i + dr[k];
                        int ncol = j + dc[k];
                        int v = nrow * n + ncol;
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                            grid[nrow][ncol]) {
                            s.insert(ds.find(v));
                        }
                    }
                    for(auto it:s){
                        cnt+=ds.size[it];
                    }
                    res=max(cnt,res);
                }
            }
        }
        if(!b)return n*n;
        return res;
    }
};