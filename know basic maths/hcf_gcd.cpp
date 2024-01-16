#include <bits/stdc++.h>
using namespace std;

int method1(int a, int b) // O(min(a,b))
{
  int mini = min(a, b);

  for (int i = mini; i >= 1; i--)
  {
    /* code */
    if (a % i == 0 && b % i == 0)
    {
      return i;
    }
  }
}

int euclidean(int a, int b) // O(log(phi)(min(a,b))) -> Euclidean ALgorithm
{
  while (a > 0 && b > 0)
  {
    /* code */
    if (a > b)
    {
      a = a % b;
    }
    else
    {
      b = b % a;
    }
  }
  if (a == 0)
  {
    return b;
  }
  return a;
}

int main()
{
  int a, b;
  cin >> a;
  cin >> b;

  cout << method1(a, b) << endl;
  cout << euclidean(a, b);
}