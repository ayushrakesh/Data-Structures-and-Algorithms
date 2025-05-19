class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        int n = points.size();
        vector<pair<double, int>> v;
        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < n; i++) {
            v.push_back({sqrt(points[i][0] * points[i][0] +
                              points[i][1] * points[i][1]),
                         i});
        }

        for (int i = 0; i < k; i++) {
            pq.push(v[i]);
        }

        for (int i = k; i < n; i++) {
            if (v[i].first < pq.top().first) {
                pq.pop();
                pq.push(v[i]);
            }
        }
        while (!pq.empty()) {
            res.push_back({points[pq.top().second]});
            pq.pop();
        }
        return res;
    }
};