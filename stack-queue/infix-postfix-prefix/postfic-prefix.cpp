#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
  switch (c)
  {
  case '+':
  case '-':
  case '*':
  case '/':
    return true;

  default:
    return false;
  }
}

string postfixToPrefix(string s)
{
  stack<string> st;
  string res = "";

  for (int i = 0; i < s.size(); i++)
  {
    if (isOperator(s[i]))
    {
      // string a=s[i];
      string b = st.top();
      st.pop();
      string c = st.top();
      st.pop();

      st.push(s[i] + c + b);
    }
    else
    {
      st.push(string(1, s[i]));
    }
  }
  return st.top();
}
int main()
{
  string s;
  cin >> s;

  cout << postfixToPrefix(s) << endl;
}