#include <bits/stdc++.h>
using namespace std;

TreeNode *solve(TreeNode *root, int val)
{
  if (!root)
    return root;

  if (val == root->val)
    return root;
  else if (val > root->val)
  {
    return solve(root->right, val);
  }
  else
  {
    return solve(root->left, val);
  }
}
TreeNode *searchBST(TreeNode *root, int val)
{
  // if(!root)return NULL;

  return solve(root, val);
}