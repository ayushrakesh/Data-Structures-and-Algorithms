#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
  stack<int> st;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{')
    {
      st.push(s[i]);
    }
    else
    {
      if (!st.empty())
      {
        if (s[i] == ')' && st.top() == '(')
        {
          st.pop();
          continue;
        }
        else if (s[i] == ']' && st.top() == '[')
        {
          st.pop();
          continue;
        }
        else if (s[i] == '}' && st.top() == '{')
        {
          st.pop();
          continue;
        }

        st.push(s[i]);
      }
      else
      {
        st.push(s[i]);
      }
    }
  }
  return st.empty() ? true : false;
}

int main()
{
  string s;
  cin >> s;

  cout << isValid(s) << endl;
}