#include <bits/stdc++.h>
using namespace std;

int sumOfD(vector<int> v, int mid)
{
  int sum = 0;

  for (int i = 0; i < v.size(); i++)
  {
    sum += ceil((double)v[i] / (double)mid);
  }
  return sum;
}

int smallestDivisorGivenThreshold(vector<int> v, int thres)
{
  int low = 1, high = *max_element(v.begin(), v.end());
  int ans = high;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (sumOfD(v, mid) <= thres)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;
  vector<int> v;
  int a = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }
  int thres = 0;
  cin >> thres;

  cout << smallestDivisorGivenThreshold(v, thres) << endl;
}