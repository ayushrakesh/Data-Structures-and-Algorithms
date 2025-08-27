class DisJointSet {
public:
    vector<int> parent, size;

    DisJointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        int extraedges=0;

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(ds.find(u) == ds.find(v)){
                extraedges++;
            }
            else{
                ds.unionBySize(connections[i][0],connections[i][1]);
            }
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)comp++;
        }

        if(extraedges >= comp-1){
            return comp-1;
        }
        return -1;
    }
};