#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> v, int n)
{
  int i = 0;

  for (int j = 1; j < n; j++)
  {
    if (v[j] != v[i])
    {
      v[i + 1] = v[j];
      i++;
    }
  }
  return i + 1;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v.push_back(a);
  }

  cout << removeDuplicates(v, n) << endl;
}