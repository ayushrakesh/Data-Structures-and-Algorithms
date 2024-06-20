#include <bits/stdc++.h>
using namespace std;
int largetRectangle1(vector<int> v)
{
  int n = v.size();
  stack<int> st;
  int left[n];
  int right[n];

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && v[st.top()] >= v[i])
    {
      st.pop();
      /* code */
    }
    if (st.empty())
    {
      left[i] = 0;
    }
    else
    {
      left[i] = st.top() + 1;
    }

    st.push(i);
  }

  while (!st.empty())
  {
    st.pop();
  }

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && v[st.top()] >= v[i])
    {
      st.pop();
    }
    if (st.empty())
    {
      right[i] = n - 1;
    }
    else
    {
      right[i] = st.top() - 1;
    }
    st.push(i);
  }

  for (int i = 0; i < n; i++)
  {
    cout << left[i] << " " << right[i] << endl;
  }

  int maxi = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    int area = v[i] * (right[i] - left[i] + 1);
    maxi = max(maxi, area);
  }
  return maxi;
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

  cout << largetRectangle1(v) << endl;
}