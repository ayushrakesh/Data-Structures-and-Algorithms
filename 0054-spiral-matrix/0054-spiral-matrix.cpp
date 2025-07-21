class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int d = m * n;

        while (top<=bottom && left<=right) {
            int l = left;
            while (l <= right) {
                res.push_back(matrix[top][l]);
                l++;
                cout << "top" << " ";
            }
            top++;
            int t = top;
            while (t <= bottom) {
                res.push_back(matrix[t][right]);
                t++;
                cout << "right" << " ";
            }
            right--;

            if (top <= bottom) {
                int r = right;
                while (r >= left) {
                    res.push_back(matrix[bottom][r]);
                    r--;
                    cout << "bottom" << " ";
                }
                bottom--;
            }
            if (left <= right) {
                int b = bottom;
                while (b >= top) {
                    res.push_back(matrix[b][left]);
                    b--;
                    cout << "left" << " ";
                }
                left++;
            }
        }
        return res;
    }
};