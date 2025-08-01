class Solution {
public:
    void solve(int ind, vector<int>& candidates, int target, vector<int>& v,
               vector<vector<int>>& res) {
        if(target<0)return;
        if (target == 0) {
            res.push_back(v);
            return;
        }
        if (ind >= candidates.size()) {
            if (target == 0) {
                res.push_back(v);
            }
            return;
        }

        v.push_back(candidates[ind]);
        solve(ind+1, candidates, target - candidates[ind], v, res);

        v.pop_back();

        int i=ind+1;
        while(i<candidates.size() && candidates[i]==candidates[ind]){
            i++;
        }
        solve(i, candidates, target, v, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        solve(0, candidates, target, v, res);
        return res;
    }
};