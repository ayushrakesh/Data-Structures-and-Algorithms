#include <bits/stdc++.h>
using namespace std;
int prec(char c)
{
  if (c == '+' || c == '-')
    return 1;
  if (c == '*' || c == '/')
    return 2;
  if (c == '^')
    return 3;
  else
    return -1;
}
void solve(string s, string &res)
{
  stack<char> st;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
    {
      st.push(s[i]);
    }
    else if (s[i] == ')')
    {
      while (st.top() != '(' && !st.empty())
      {
        char c = st.top();
        st.pop();
        res.push_back(c);
      }
      if (!st.empty())
        st.pop();
    }
    else if (prec(s[i]) == -1)
    {
      res.push_back(s[i]);
    }
    else
    {
      while (!st.empty() && prec(st.top()) >= prec(s[i]))
      {
        char t = st.top();
        st.pop();
        res.push_back(t);
      }
      st.push(s[i]);
    }
  }

  while (!st.empty())
  {
    res.push_back(st.top());
    st.pop();
  }
}
// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string s)
{
  // Your code here

  string res = "";
  solve(s, res);
  return res;
}
int main()
{
  string s;
  cin >> s;

  string res = infixToPostfix(s);

  cout << res << endl;
}