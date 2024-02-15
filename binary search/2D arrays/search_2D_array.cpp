#include <bits/stdc++.h>
using namespace std;

bool searchIn2Dmatrix(vector<vector<int>> v, int target)
{
  int n = v.size();
  int m = v[0].size();

  int low = 0, high = m * n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    int row = mid / m;
    int col = mid % m;

    if (v[row][col] == target)
      return true;
    else if (v[row][col] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false;
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
  int target;
  cin >> target;

  cout << searchIn2Dmatrix(v, target) << endl;
}