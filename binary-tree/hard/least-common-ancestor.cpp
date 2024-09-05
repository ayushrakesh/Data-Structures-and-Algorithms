#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int d)
  {
    this->val = d;
    left = right = nullptr;
  }
};

void solve(TreeNode *root, vector<TreeNode *> &path, TreeNode *node)
{
  if (root == NULL)
    return;

  path.push_back(root);

  if (root->val == node->val)
  {
    return;
  }

  if (root->left != NULL)
  {
    solve(root->left, path, node);
    path.pop_back();
  }

  if (root->right != NULL)
  {
    solve(root->right, path, node);
    path.pop_back();
  }
}
TreeNode *brute(TreeNode *root, TreeNode *p, TreeNode *q)
{
  vector<TreeNode *> a, b;
  solve(root, a, p);
  solve(root, b, q);

  int size = min(a.size(), b.size());

  for (int i = size - 1; i >= 0; i--)
  {
    if (a[i] == b[i])
    {
      return a[i];
    }
  }
  return NULL;
}
TreeNode *optimal(TreeNode *root, TreeNode *p, TreeNode *q)
{
  if (root == NULL)
    return NULL;

  if (root->val == p->val || root->val == q->val)
  {
    return root;
  }
  TreeNode *left = optimal(root->left, p, q);
  TreeNode *right = optimal(root->right, p, q);

  if (left != NULL && right != NULL)
  {
    return root;
  }
  if (left != NULL && right == NULL)
    return left;
  if (left == NULL && right != NULL)
    return right;

  if (left == NULL && right == NULL &&
      (root->val == p->val || root->val == q->val))
  {
    return root;
  }
  return NULL;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  // return brute(root, p, q);
  return optimal(root, p, q);
}