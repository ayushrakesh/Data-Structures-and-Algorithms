#include <bits/stdc++.h>
using namespace std;

int res = -1;
void solve(Node *root, int input)
{
  if (!root)
    return;

  if (root->data >= input)
  {
    res = root->data;
    solve(root->left, input);
    return;
  }

  solve(root->right, input);
  return;
}
int findCeil(Node *root, int input)
{
  // if (root == NULL) return -1;
  // int res=-1;
  solve(root, input);
  return res;

  // Your code here
}