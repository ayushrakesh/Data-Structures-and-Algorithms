class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        vector<int> prevsmaller(n, -1), nextsmaller(n, -1);
        stack<int> st, stt;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty())
                prevsmaller[i] = -1;
            else
                prevsmaller[i] = st.top();
            st.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!stt.empty() && heights[stt.top()] >= heights[i]) {
                stt.pop();
            }
            if (stt.empty())
                nextsmaller[i] = n;
            else
                nextsmaller[i] = stt.top();
            stt.push(i);
        }
        for (int i = 0; i < n; i++) {
            int prev = prevsmaller[i];
            int next = nextsmaller[i];

            res = max(res, heights[i] * (next - prev - 1));
        }
        return res;
    }
};