#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  int maxAmount = max(a * c, b * c);
  cout << maxAmount << endl;
}
