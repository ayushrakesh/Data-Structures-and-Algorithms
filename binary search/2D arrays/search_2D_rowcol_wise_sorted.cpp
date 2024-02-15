#include <bits/stdc++.h>
using namespace std;

bool searchInRowAndColwiseSorted(vector<vector<int>> v, int target)
{
  int row = 0;
  int col = v[0].size() - 1;

  while (row < v.size() || col >= 0)
  {
    /* code */
    if (v[row][col] == target)
      return true;
    else if (v[row][col] < target)
      row++;
    else
      col--;
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

  cout << searchInRowAndColwiseSorted(v, target) << endl;
}