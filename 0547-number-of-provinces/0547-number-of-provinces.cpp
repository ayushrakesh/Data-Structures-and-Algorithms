class Solution {
public:
    void solve(int node,vector<vector<int>> isConnected,vector<bool>&visited){
        visited[node]=true;

        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i] && !visited[i]){
                solve(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int res=0;
        vector<bool>visited(n+1,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                solve(i, isConnected, visited);
                res++;
            }
        }
        return res;
    }
};