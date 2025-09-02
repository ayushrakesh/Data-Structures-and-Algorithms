class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        int a = 0, b = 0, c = 0;

        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (s[i] == ')') {
                    if (!st.empty() && st.top() == '(')
                        st.pop();
                    else
                        return false;
                } else if (s[i] == '}') {
                    if (!st.empty() && st.top() == '{')
                        st.pop();
                    else
                        return false;
                } else if (s[i] == ']') {
                    if (!st.empty() && st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
            }
        }
        return st.empty();
    }
};