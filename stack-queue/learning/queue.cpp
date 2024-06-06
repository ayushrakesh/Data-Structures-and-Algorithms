#include <bits/stdc++.h>
using namespace std;

int main()
{
  queue<int> t;
  t.push(1);
  t.push(2);
  t.push(4);
  t.push(5);

  queue<int> q = t;
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
  cout << t.front() << endl;

  t.pop();
  cout << t.front() << endl;

  t.push(7);
  cout << t.back() << endl;

  // t.pop();
  // t.pop();
  // t.pop();
  // cout << t.size() << endl;

  cout << t.front() << endl;
  cout << t.back() << endl;

  while (!t.empty())
  {
    cout << t.front() << " ";
    t.pop();
  }
}