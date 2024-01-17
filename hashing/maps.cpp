#include <bits/stdc++.h>
using namespace std;
pair<int, int> maxMinFrequency(unordered_map<int, int> mmp)
{
  int minEle = INT_MAX;
  int maxEle = INT_MIN;

  for (auto it : mmp)
  {
    if (it.second < minEle)
    {
      minEle = it.second;
    }
    if (it.second > maxEle)
    {
      maxEle = it.second;
    }
  }

  return make_pair(minEle, maxEle);
}
int main()
{
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // ordered map -> sorted acc to keys by default
  unordered_map<int, int> mmp;

  for (int i = 0; i < n; i++)
  {
    mmp[arr[i]]++;
  }

  int q = 0;
  cin >> q;

  while (q != 0)
  {
    int number;
    cin >> number;

    cout << mmp[number] << endl;
    q--;
  }

  pair<int, int> p = maxMinFrequency(mmp);

  cout << p.first << " " << p.second << endl;
}