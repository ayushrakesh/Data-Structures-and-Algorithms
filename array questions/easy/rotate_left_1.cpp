#include <bits/stdc++.h>
using namespace std;
void rotateLeftOne(vector<int> &v)
{
  int temp = v[0];

  for (int i = 1; i < v.size(); i++)
  {
    v[i - 1] = v[i];
  }
  v[v.size() - 1] = temp;
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
  rotateLeftOne(v);
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
}