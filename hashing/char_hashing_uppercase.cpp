#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin >> s;

  int hashing[26] = {0};

  for (int i = 0; i < s.size(); i++)
  {
    hashing[s[i] - 'A']++;
  }

  int q = 0;
  cin >> q;

  while (q != 0)
  {

    char c;
    cin >> c;

    cout << hashing[c - 'A'] << endl;

    q--;
  }
}