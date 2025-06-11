class Solution {
public:
    bool isPalindrome(string &t){
        int i=0;
        int j=t.size()-1;

        while(i<j){
            if(t[i]!=t[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int ind, vector<string>& v, string& s,
               vector<vector<string>>& res) {
        int n = s.size();
        if (ind >= n) {
            res.push_back(v);
            return;
        }

        for (int i = ind; i < n; i++) {
            string t = s.substr(ind, i - ind + 1);
            if (isPalindrome(t)) {
                v.push_back(t);
                solve(i + 1, v, s, res);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;

        solve(0, v, s, res);
        return res;
    }
};