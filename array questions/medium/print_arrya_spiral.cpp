#include <bits/stdc++.h>
// #include <vector>
using namespace std;
// The main driver code functionality starts from here

vector<int> printSpiralMatrix(vector<vector<int>> &v)
{

  int left = 0;
  int right = v[0].size() - 1;
  vector<int> res;

  int top = 0;
  int bottom = v.size() - 1;

  while (left <= right && top <= bottom)
  {
    for (int i = top; i <= right; i++)
    {
      /* code */
      res.push_back(v[left][i]);
    }
    top++;

    for (int i = top; i <= bottom; i++)
    {
      /* code */
      res.push_back(v[i][right]);
    }
    right--;

    if (top <= bottom)
    {
      for (int i = right; i >= left; i--)
      {
        /* code */
        res.push_back(v[bottom][i]);
      }
      bottom--;
    }

    if (left <= right)
    {
      for (int i = bottom; i >= top; i--)
      {
        /* code */
        res.push_back(v[i][left]);
      }
      left++;
    }
  }
  return res;
}

int main()
{
  int n, m;
  cin >> n >> m;
  int a = 0;
  //  here, we are trying to create a vector that contains the variable "n."
  //  and a vector of functionality each of size "m."

  vector<vector<int>> vec(n, vector<int>(m));
  // for loop to run through the variables n to m
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a;
      vec[i][j] = a;
    }
  }

  vector<int> res = printSpiralMatrix(vec);

  // for loop to run through the variables m to n
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }

  return 0;
  // The main driver code functionality ends from here
}