#include <bits/stdc++.h>
using namespace std;
vector<int> leadersArray(vector<int> v)
{

  vector<int> res;
  int maxi = INT_MIN;

  for (int i = v.size() - 1; i >= 0; i--)
  {
    /* code */
    if (v[i] > maxi)
    {
      res.push_back(v[i]);
      // maxi = max(maxi, v[i]);
      maxi = v[i];
    }
  }

  return res;
}
int main()
{
  int n;
  cin >> n;
  vector<int> v;
  int a;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  vector<int> leaders = leadersArray(v);

  for (int i = 0; i < leaders.size(); i++)
  {
    cout << leaders[i] << " ";
  }
}