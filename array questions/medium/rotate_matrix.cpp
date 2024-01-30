#include <bits/stdc++.h>
// #include <vector>
using namespace std;
// The main driver code functionality starts from here

void setMatrixZeroes(vector<vector<int>> &v)
{

  for (int i = 0; i < v.size(); i++)
  {
    for (int j = i + 1; j < v[0].size(); j++)
    {
      /* code */
      swap(v[i][j], v[j][i]);
    }
  }

  for (int i = 0; i < v.size(); i++)
  {
    reverse(v[i].begin(), v[i].end());
  }
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

  setMatrixZeroes(vec);

  // for loop to run through the variables m to n
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << vec[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
  // The main driver code functionality ends from here
}