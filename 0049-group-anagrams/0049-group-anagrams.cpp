class Solution {
public:
    vector<vector<string>> better(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < n; i++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
    vector<vector<string>> optimal(vector<string>& v) {
        int n = v.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (int i = 0; i < n; i++) {
            string s = v[i];
            vector<int> fre(26, 0);
            for (int j = 0; j < s.size(); j++) {
                fre[s[j] - 'a']++;
            }

            string temp = "";
            for (int i = 0; i < 26; i++) {
                temp += to_string(fre[i]) + "#";
            }
            mp[temp].push_back(s);
        }
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // return better(strs);
        return optimal(strs);
    }
};