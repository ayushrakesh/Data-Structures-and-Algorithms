#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> v, int target)
{
  int n = v.size();
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    /* code */

    int mid = (low + high) / 2;

    if (v[mid] >= target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

vector<int> rowWithMaxOnes(vector<vector<int>> mat)
{
  int n = mat.size();
  int m = mat[0].size();
  int maxi = 0;
  int index = -1;

  for (int i = 0; i < n; i++)
  {

    int count = m - lowerBound(mat[i], 1);

    if (count > maxi)
    {
      maxi = count;
      index = i;
    }
  }
  if (maxi != 0)
  {
    return {index, maxi};
  }
  else
  {
    return {0, 0};
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(m);
  int a = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a;
      v[i].push_back(a);
    }
  }

  cout << rowWithMaxOnes(v)[0] << " " << rowWithMaxOnes(v)[1] << endl;
}