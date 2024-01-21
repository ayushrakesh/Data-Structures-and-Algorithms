#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;

  string s = bitset<10>(n).to_string().substr(10 - log2(n + 1));

  cout << s << endl;
}
