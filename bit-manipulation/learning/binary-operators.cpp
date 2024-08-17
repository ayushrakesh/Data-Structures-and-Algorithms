#include <bits/stdc++.h>
using namespace std;

void swapVariables(int &a, int &b)
{
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
int findKthBit(int n, int k)
{
  if (((1 << k) & n) == 0)
    return 0;
  else
    return 1;
}
int setKthBit(int &l, int k)
{
  return (l | (1 << k));
}
int clearKthBit(int l, int k)
{
  return (l & ~(1 << k));
}
int toggleKthBit(int l, int k)
{
  return l ^ (1 << k);
}
void checkNIsPowerOf2(int l)
{
  if (l & (l - 1) == 0)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

int main()
{
  int a = 2;
  int b = 0;

  int c = a & b; // AND
  int d = a | b; // OR
  int e = ~a;    // NOT

  int f = a << 1; // LEFT SHIFT by 1
  int g = a << 2; // left shift by 2

  int h = a >> 1; // right shift by 1
  int i = a >> 2; // right shift by 2

  int j = a ^ b; // XOR -> even 1's -> 0 otherwise 1

  cout << c << endl;
  cout << d << endl;
  cout << e << endl;

  cout << f << endl;
  cout << g << endl;

  cout << h << endl;
  cout << i << endl;

  cout << j << endl;

  int *p = &a;
  int *q = &b;

  cout << "-------------" << endl;
  swapVariables(a, b);
  cout << a << " " << b << endl;

  cout << "-------------" << endl;

  int k = 1;
  cout << findKthBit(10, 0) << endl;

  cout << "-------------" << endl;

  int l = 4;
  cout << setKthBit(l, 1) << endl;
  cout << "-------------" << endl;

  int m = 6;
  cout << clearKthBit(m, 0) << endl;
  cout << "-------------" << endl;

  int t = 7;
  cout << toggleKthBit(l, 2) << endl;
  cout << "-------------" << endl;

  int o = 16;
  checkNIsPowerOf2(o);
  cout << "-------------" << endl;
}
