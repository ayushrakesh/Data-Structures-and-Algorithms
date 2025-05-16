class Solution {
public:
    int solve(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        priority_queue<int> proheap;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            capheap;

        for (int i = 0; i < n; i++) {
            capheap.push(make_pair(capital[i], i));
        }

        while (k--) {
            while (!capheap.empty() && w >= capheap.top().first) {
                int ind = capheap.top().second;
                capheap.pop();

                proheap.push(profits[ind]);
            }

            if (proheap.empty())
                break;

            w += proheap.top();
            proheap.pop();
        }
        return w;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        return solve(k, w, profits, capital);
    }
};