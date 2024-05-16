#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &s)
{
  stack<int> t;
  int l = s.size();
  int temp = 0;
  int cnt = 0;

  while (t.size() != l)
  {
    int top = s.top();
    s.pop();
    bool flag = false;

    while (!s.empty())
    {

      if (s.top() <= top)
      {
        int a = s.top();
        s.pop();
        t.push(a);
      }
      else
      {
        temp = s.top();
        s.pop();

        s.push(top);
        flag = true;
        break;
      }
    }

    if (flag)
    {
      while (t.size() < cnt)
      {
        int c = t.top();
        t.pop();
        s.push(c);
        /* code */
      }
      s.push(temp);
      continue;
    }

    while (t.size() > cnt)
    {
      int d = t.top();
      t.pop();
      s.push(d);
    }

    t.push(top);
    cnt++;
  }

  while (!t.empty())
  {
    int f = t.top();
    t.pop();

    s.push(f);
    /* code */
  }
}

int main()
{
  stack<int> s;
  s.push(2);
  s.push(32);
  s.push(41);
  s.push(3);
  s.push(11);

  sortStack(s);

  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}