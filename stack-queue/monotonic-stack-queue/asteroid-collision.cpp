#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
  stack<int> st;
  stack<int> s;
  vector<int> res;
  st.push(asteroids[0]);
  int n = asteroids.size();

  for (int i = 1; i < n; i++)
  {
  }

  while (!st.empty())
  {
    s.push(st.top());
    st.pop();
  }

  while (!s.empty())
  {
    res.push_back(s.top());
    s.pop();
  }

  return res;
}
int main()
{
  vector<int> v = {10, 2, -5};
  vector<int> res = asteroidCollision(v);

  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}