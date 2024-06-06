#include <bits/stdc++.h>
using namespace std;

queue<int> a;
queue<int> b;

void push(int x)
{
  b.push(x);

  while (!a.empty())
  {
    int s = a.front();
    b.push(s);
    a.pop();
  }

  swap(a, b);
}

int pop()
{
  int x = a.front();
  a.pop();
  return x;
}

int top() { return a.front(); }

bool empty() { return a.empty() ? true : false; }
int main()
{
}