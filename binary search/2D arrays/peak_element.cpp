#include <bits/stdc++.h>
using namespace std;

int maxElement(vector<vector<int>> v, int col)
{

  int maxi = v[0][col];
  int ind = 0;

  for (int i = 0; i < v.size(); i++)
  {
    /* code */
    if (v[i][col] > maxi)
      ind = i;
    maxi = v[i][col];
  }
  return ind;
}

vector<int> peakElement(vector<vector<int>> v)
{
  int n = v.size();
  int m = v[0].size();

  int low = 0, high = m - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    int rowInd = maxElement(v, mid);

    int left = mid >= 1 ? v[rowInd][mid - 1] : -1;
    int right = mid < m - 1 ? v[rowInd][mid + 1] : -1;

    if (v[rowInd][mid] > left && v[rowInd][mid] > right)
      return {rowInd, mid};
    else if (v[rowInd][mid] < left)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return {-1, -1};
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
  vector<int> res = peakElement(v);
  cout << res[0] << " " << res[1] << endl;
}