#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int hashing[15] = {0};

  for (int i = 0; i < n; i++)
  {
    hashing[arr[i]]++;
  }

  int q = 0;
  cin >> q;

  while (q != 0)
  {
    int a;
    cin >> a;

    cout << hashing[a] << endl;

    q--;
  }
}