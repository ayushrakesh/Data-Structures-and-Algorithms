#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
  stack<char> st;
  string res;
  int cnt = 0;

  for (int i = 0; i < num.size(); i++)
  {
    char curr = num[i];
    while (!st.empty() && curr < st.top() && cnt < k)
    {
      st.pop();
      cnt++;
    }

    st.push(curr);
  }

  while (cnt < k && !st.empty())
  {
    st.pop();
    cnt++;
  }

  while (!st.empty())
  {
    res.push_back(st.top());
    st.pop();
  }

  reverse(res.begin(), res.end());

  // Remove leading zeros
  int start = 0;
  while (res[start] == '0')
  {
    start++;
  }

  res = res.substr(start);

  // If the result is empty, return "0"
  return res.empty() ? "0" : res;
}

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;

  string res = removeKdigits(s, k);

  cout << res << endl;
}