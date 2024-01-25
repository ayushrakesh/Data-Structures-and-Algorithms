#include <bits/stdc++.h>
using namespace std;

int stocksBuySell(vector<int> v)
{
  int profit = 0;

  int mini = v[0];

  for (int i = 1; i < v.size(); i++)
  {
    int cost = v[i] - mini;
    profit = max(profit, cost);

    mini = min(mini, v[i]);
  }

  return profit;
}
int main()
{
  int n;
  cin >> n;

  vector<int> v;

  int a;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  cout << stocksBuySell(v) << endl;
}