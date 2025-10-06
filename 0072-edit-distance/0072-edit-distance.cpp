class Solution {
public:
    int solve(int i, int j, string s, string t) {
        int n = s.size();
        int m = t.size();

        if (i >= n)
            return m - j;
        if (j >= m)
            return n - i;

        if (s[i] == t[j])
            return solve(i + 1, j + 1, s, t);
        return 1 + min(solve(i, j + 1, s, t),
                       min(solve(i + 1, j, s, t), solve(i + 1, j + 1, s, t)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return solve(0, 0, word1, word2);
    }
};