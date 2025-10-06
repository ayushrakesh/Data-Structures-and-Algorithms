class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        sort(s.begin(), s.end());
        int c = g.size();
        int res = 0;

        sort(g.begin(), g.end());
        int j = 0;
        for (int i = 0; i < c; i++) {
            while (j<n && s[j] < g[i])
                j++;
            if (j < n) {
                res++;
                j++;
            }
        }
        return res;
    }
};