class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        vector<vector<int>> v(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    v[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int d=q.front().second;
            q.pop();

            res[row][col]=min(res[row][col],d);

            vector<int> nr={-1,0,1,0};
            vector<int> nc={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow=row+nr[i];
                int ncol=col+nc[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !v[nrow][ncol]){
                    v[nrow][ncol]=1;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
        return res;
    }
};