class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int res = 0;
        vector<bool> v(n, false);

        for (int i = 0; i < n; i++) {
            bool b = false;
            for (int j = 0; j < n; j++) {
                if (v[j] == false && baskets[j] >= fruits[i]) {
                    b = true;
                    v[j] = true;
                    break;
                }
            }
            if (!b)
                res++;
        }
        return res;
    }
};