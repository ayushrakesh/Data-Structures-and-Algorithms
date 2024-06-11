#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
  int n = A.size();
  vector<int> res;

  stack<int> st;

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && st.top() >= A[i])
    {
      st.pop();
    }
    if (!st.empty())
    {
      res.push_back(st.top());
    }
    else
    {
      res.push_back(-1);
    }
    st.push(A[i]);
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  int a = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  vector<int> res = prevSmaller(v);

  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}