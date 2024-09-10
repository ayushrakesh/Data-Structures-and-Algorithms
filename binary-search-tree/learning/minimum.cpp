#include <bits/stdc++.h>
using namespace std;

int solve(Node *root)
{
  if (!root)
    return -1;

  if (root->left)
  {
    return solve(root->left);
  }
  return root->data;
}
int minValue(Node *root)
{
  // Code here
  return solve(root);
}