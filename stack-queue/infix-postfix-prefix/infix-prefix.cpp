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
string infixToPrefix(string s)
{
  reverse(s.begin(), s.end());
  stack<char> st;
  string res = "";

  for (int i = 0; i < s.size(); i++)
  {
    char c = s[i];

    if (c == ')')
    {
      st.push(c);
    }
    else if (c == '(')
    {
      while (c != ')' && !st.empty())
      {
        /* code */
        char a = st.top();
        st.pop();
        res.push_back(a);
      }
      if (!st.empty())
      {
        st.pop();
      }
    }
    else if (prec(c) == -1)
    {
      res.push_back(c);
    }
    else
    {
      while ((prec(c) < prec(st.top())) && (!st.empty()))
      {
        char b = st.top();
        st.pop();
        res.push_back(b);
        /* code */
      }
      st.push(c);
    }
  }

  while (!st.empty())
  {
    char g = st.top();
    st.pop();
    res.push_back(g);
    /* code */
  }
  return res;
}
int main()
{
  string s;
  cin >> s;

  cout << infixToPrefix(s) << endl;
}