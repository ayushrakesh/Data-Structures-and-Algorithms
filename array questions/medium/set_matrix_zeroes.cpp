#include <iostream>
#include <vector>
using namespace std;
// The main driver code functionality starts from here

void setMatrixZeroes(vector<vector<int>> &v)
{
  int row[v.size()] = {0};
  int col[v.at(0).size()] = {0};

  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[0].size(); j++)
    {
      /* code */
      if (v[i][j] == 0)
      {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }

  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[0].size(); j++)
    {
      if (v[i][j] == 1)
      {
        if (row[i] == 1 || col[j] == 1)
        {
          v[i][j] = 0;
        }
      }
    }
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