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
string postToInfix(string exp)
{
  // Write your code here

  stack<string> st;

  for (int i = 0; i < exp.size(); i++)
  {
    if (isOperator(exp[i]))
    {
      string a = st.top();
      st.pop();
      string b = st.top();
      st.pop();
      // string temp=;
      st.push('(' + b + exp[i] + a + ')');
    }
    else
    {
      st.push(string(1, exp[i]));
    }
  }
  return st.top();
}
int main()
{
  string s;
  cin >> s;

  cout << postToInfix(s) << endl;
}