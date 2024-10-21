#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDepth(string s)
  {
    int n = s.size();
    stack<char> st;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
      {
        st.push('(');
      }
      else if (s[i] == ')' && !st.empty() && st.top() == '(')
      {
        st.pop();
      }
      cnt = max(cnt, static_cast<int>(st.size()));
    }
    return cnt;
  }
};