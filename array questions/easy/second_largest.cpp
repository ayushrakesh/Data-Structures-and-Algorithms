#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> v, int n)
{
  int largest = v[0];
  int slargest = INT_MIN;

  for (int i = 1; i < n; i++)
  {
    if (v[i] > largest)
    {
      slargest = largest;

      largest = v[i];
    }

    else if (v[i] < largest && v[i] > slargest)
    {
      slargest = v[i];
    }
  }
  return slargest;
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

  cout << secondLargest(v, n) << endl;
}