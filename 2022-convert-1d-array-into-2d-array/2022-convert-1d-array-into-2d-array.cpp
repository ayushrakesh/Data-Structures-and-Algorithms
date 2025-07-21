class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        int i = 0, j = n - 1;

        if (m * n != original.size())
            return {};
        vector<int> temp;
        while (m--) {

            for (int k = i; k <= j; k++) {
                temp.push_back(original[k]);
            }
            res.push_back(temp);

            i += n;
            j += n;
            temp.clear();
        }
        return res;
    }
};