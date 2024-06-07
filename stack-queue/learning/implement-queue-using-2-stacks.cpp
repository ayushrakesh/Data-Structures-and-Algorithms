#include <bits/stdc++.h>
using namespace std;

stack<int> a, b;

void push(int x)
{
  a.push(x);
}

int pop()
{
  // int cnt = 0;
  while (a.size() > 1)
  {
    int x = a.top();
    a.pop();

    b.push(x);
  }

  int y = a.top();
  a.pop();

  // cnt = 0;

  while (b.size() > 0)
  {
    int t = b.top();
    b.pop();
    a.push(t);
  }

  return y;
}

int peek()
{
  // int si = a.size();
  // int cnt = 0;

  while (a.size() > 1)
  {
    int t = a.top();
    a.pop();
    b.push(t);
  }

  int s = a.top();
  // cnt = 0;

  while (b.size() > 0)
  {
    int r = b.top();
    b.pop();

    a.push(r);
  }
  return s;
}

bool empty()
{
  return a.size() == 0 ? true : false;
}

int main() {}