#include <bits/stdc++.h>
using namespace std;

int res = -1;
void solve(Node *root, int x)
{
  if (!root)
    return;

  if (root->data <= x)
  {
    res = root->data;
    solve(root->right, x);
    return;
  }
  solve(root->left, x);
  return;
}
int floor(Node *root, int x)
{
  // Code here
  solve(root, x);
  return res;
}