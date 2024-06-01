#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &st)
{
  if (st.size() == 2)
  {
    int top = st.top();
    st.pop();

    swap(top, st.top());
    st.push(top);
    return;
  }

  reverseStack(st);

  // int top=st.top();
  // st.pop();

  int cnt = 0;
  while (cnt < st.size() - 1)
  {
    int t = st.top();
    st.pop();
    swap(t, st.top());
    st.push(t);
    cnt++;
  }
}
int main()
{
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);

  reverseStack(st);
}