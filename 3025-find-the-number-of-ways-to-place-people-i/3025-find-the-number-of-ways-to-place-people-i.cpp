class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                int a = points[i][0];
                int b = points[i][1];
                int c = points[j][0];
                int d = points[j][1];
                if (a <= c && b >= d) {
                    bool flag = false;
                    for (int k = 0; k < n; k++) {
                        if (k == j || k == i)
                            continue;
                        if (a <= points[k][0] && points[k][0] <= c &&
                            d <= points[k][1] && points[k][1] <= b) {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                        res++;
                }
            }
        }
        return res;
    }
};