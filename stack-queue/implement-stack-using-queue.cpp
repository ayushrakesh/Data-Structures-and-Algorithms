#include <bits/stdc++.h>
using namespace std;

queue<int> a;

void push(int x)
{
  a.push(x);
  int s = a.size();
  int temp = 0;
  while (temp < (s - 1))
  {
    int x = a.front();
    a.pop();
    a.push(x);
  }
  temp++;
  // swap(a, b);
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