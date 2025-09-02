class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<map<char, int>, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            string s = strs[i];
            int l = s.size();
            map<char, int> np;

            for (int j = 0; j < l; j++) {
                np[s[j]]++;
            }
            mp[np].push_back(i);
        }
        vector<vector<string>> res;
        for (auto it : mp) {
            vector<int> temp = it.second;
            vector<string> v;
            for (int i = 0; i < temp.size(); i++) {
                v.push_back(strs[temp[i]]);
            }
            res.push_back(v);
        }
        return res;
    }
};