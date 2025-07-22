class Solution {
public:
    void solve(int ind, string s, string& t, vector<string>& res) {
        if (ind >= s.size()) {
            res.push_back(t);
            return;
        }
        if (s[ind] <= '9') {
            t.push_back(s[ind]);
            solve(ind + 1, s, t, res);
            t.pop_back();
        } else {
            if (s[ind] <= 'Z') {
                t.push_back(s[ind]);
                solve(ind + 1, s, t, res);
                t.pop_back();
                t.push_back(s[ind] + 32);
                solve(ind + 1, s, t, res);
                t.pop_back();
            } else {
                t.push_back(s[ind]);
                solve(ind + 1, s, t, res);
                t.pop_back();
                t.push_back(s[ind] - 32);
                solve(ind + 1, s, t, res);
                t.pop_back();
            }
        }
        return;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        int n = s.size();
        string t = "";
        solve(0, s, t, res);
        return res;
    }
};