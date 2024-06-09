#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
  stack<int> st;
  int mini;
  stack<int> minStack;

  MinStack() { mini = INT_MAX; }

  void push(int val)
  {
    st.push(val);
    mini = min(mini, val);
    minStack.push(mini);
  }

  void pop()
  {
    st.pop();
    minStack.pop();

    if (minStack.size() == 0)
    {
      mini = INT_MAX;
    }
    else
    {
      mini = minStack.top();
    }
  }

  int top() { return st.top(); }

  int getMin() { return mini; }
};

int main()
{
  MinStack obj = MinStack();

  obj.push(-1);
  obj.push(1);
  obj.push(2);
  obj.push(2);
  obj.push(-2);
  obj.pop();

  int param_3 = obj.top();
  int param_4 = obj.getMin();

  cout << param_3 << " " << param_4 << endl;
}