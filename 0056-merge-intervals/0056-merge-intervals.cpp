class Solution {
public:
    vector<vector<int>> optimal(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> res;
        int i = 0;

        while (i < n) {
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            i++;

            while (i < n && intervals[i][0] <= ce) {
                cs = min(cs, intervals[i][0]);
                ce = max(ce, intervals[i][1]);
                i++;
            }
            res.push_back({cs, ce});
        }
        return res;
    }
    vector<vector<int>> brute(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        vector<bool> used(n, false);

        for (int i = 0; i < n; i++) {
            int st = intervals[i][0];
            int en = intervals[i][1];
            if (used[i])
                continue;
            used[i] = true;
            for (int j = i + 1; j < n; j++) {
                if (!used[j] && intervals[j][0] <= en && st<=intervals[j][1]) {
                    st = min(st, intervals[j][0]);
                    en = max(en, intervals[j][1]);
                    used[j] = true;
                }
            }
            res.push_back({st, en});
        }
        return res;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
           return optimal(intervals);
        // return brute(intervals);
    }
};