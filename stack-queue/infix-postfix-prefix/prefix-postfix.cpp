#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
  switch (c)
  {
  case '+':
    return true;
  case '-':
    return true;
  case '*':
    return true;
  case '/':
    return true;
  default:
    return false;
  }
}
string preToPost(string pre_exp)
{
  stack<string> st;

  for (int i = pre_exp.size() - 1; i >= 0; i--)
  {
    if (isOperator(pre_exp[i]))
    {
      string a = st.top();
      st.pop();
      string b = st.top();
      st.pop();

      string t = a + b;
      t.push_back(pre_exp[i]);
      st.push(t);
    }
    else
    {
      st.push(string(1, pre_exp[i]));
    }
  }
  return st.top();
}

int main()
{
  string s;
  cin >> s;

  cout << preToPost(s) << endl;
}