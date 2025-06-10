class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        int res = INT_MIN;
        for (auto it : m) {
            char c = it.first;
            int f = it.second;

            if (f % 2 == 1) {
                for (auto i : m) {
                    if (i.first != c && i.second % 2 == 0) {
                        res = max(res, f - i.second);
                    }
                }
            }
        }
        return res;
    }
};