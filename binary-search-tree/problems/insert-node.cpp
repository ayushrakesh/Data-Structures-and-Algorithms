#include <bits/stdc++.h>
using namespace std;

void solve(TreeNode *root, int val)
{
  while (1)
  {
    if (val > root->val)
    {
      if (!root->right)
      {
        TreeNode *node = new TreeNode(val);
        root->right = node;
        return;
      }
      root = root->right;
    }
    else
    {
      if (!root->left)
      {
        TreeNode *node = new TreeNode(val);
        root->left = node;
        return;
      }
      root = root->left;
    }
  }
  TreeNode *node = new TreeNode(val);
  if (root->val > val)
  {
    node->left;
    return;
  }
  if (root->val < val)
  {
    node->right;
    return;
  }
}
TreeNode *insertIntoBST(TreeNode *root, int val)
{
  if (!root)
  {
    TreeNode *node = new TreeNode(val);
    return node;
  }
  TreeNode *temp = root;
  solve(temp, val);
  return root;
}