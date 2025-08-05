class Solution {
public:
    void solve(string t, int open, int close, vector<string>& res, int n) {
        if (open == close && open == n) {
            res.push_back(t);
            return;
        }

        if (open == close) {
            solve(t + '(', open + 1, close, res, n);
        } else {
            if (open < n) {
                solve(t + '(', open + 1, close, res, n);
                solve(t + ')', open, close + 1, res, n);
            } else {
                solve(t + ')', open, close+1, res, n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = 0, close = 0;
        string t = "";
        solve(t, open, close, res, n);
        return res;
    }
};