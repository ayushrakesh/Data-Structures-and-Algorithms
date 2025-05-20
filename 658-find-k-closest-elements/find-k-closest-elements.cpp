class Solution {
public:
    struct comp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (pq.size() < k) {
                pq.push({abs(x - arr[i]), arr[i]});
            } else {
                if (abs(arr[i] - x) < pq.top().first) {
                    pq.pop();
                    pq.push({abs(arr[i] - x), arr[i]});
                }
                else if(abs(arr[i] - x) == pq.top().first && (arr[i]<pq.top().second)){
                    pq.pop();
                    pq.push({abs(arr[i] - x), arr[i]});
                }
            }
        }
        vector<int> res;
        while (k--) {
            int top = pq.top().second;
            pq.pop();
            res.push_back(top);
        }
        sort(res.begin(), res.end());
        return res;
    }
};