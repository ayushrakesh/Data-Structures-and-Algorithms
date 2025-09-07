class Solution {
public:
    int optimal(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int ele = st.top();
                st.pop();

                int next = i;
                int prev = st.empty() ? -1 : st.top();
                int area = heights[ele] * (next - prev - 1);
                res = max(res, area);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int ele = st.top();
            st.pop();

            int next = n;
            int prev = st.empty() ? -1 : st.top();
            int area = heights[ele] * (next - prev - 1);
            res = max(res, area);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> v(n, 0);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][j]=='1'){
                    v[j]+=1;
                }
                else{
                    v[j]=0;
                }
            }
            res = max(res, optimal(v));
        }
        return res;
    }
};