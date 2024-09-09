#include <bits/stdc++.h>
using namespace std;
void solve(TreeNode *root)
{
  if (!root)
    return;
  if (!root->left && !root->right)
    return;

  solve(root->left);
  solve(root->right);

  if (!root->left && root->right)
  {
    return;
  }
  else if (root->left && !root->right)
  {
    root->right = root->left;
    root->left = NULL;
    return;
  }
  TreeNode *temp = root->left;
  while (temp->right)
  {
    temp = temp->right;
  }
  temp->right = root->right;
  root->right = root->left;
  root->left = NULL;
  return;
}
void flatten(TreeNode *root) { solve(root); }