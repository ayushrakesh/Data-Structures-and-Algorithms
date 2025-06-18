class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), s.size());
        int i = 0;
        int j = s.size() - 1;

        while (i <= j) {
            if (s[i] == c) {
                for (int k = 0; k < s.size(); k++) {
                    ans[k] = min(ans[k], abs(k - i));
                }
            }
            i++;
        }

        return ans;
    }
};