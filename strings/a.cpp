#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<string> v = {"dog",
                      "racecar",
                      "car"};

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}