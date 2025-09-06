class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> temp=res[i-1];
            vector<int> v={1};
            for(int j=0;j<temp.size()-1;j++){
                v.push_back(temp[j]+temp[j+1]);
            }
            v.push_back(1);
            res.push_back(v);
        }
        return res;
    }
};