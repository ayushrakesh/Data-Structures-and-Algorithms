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
void solve(TreeNode *root, vector<int> &res, int level)
{
  if (root == NULL)
    return;

  if (level == res.size())
  {
    res.push_back(root->val);
  }
  solve(root->right, res, level + 1);
  solve(root->left, res, level + 1);
}
vector<int> rightSideView(TreeNode *root)
{
  vector<int> res;
  int level = 0;
  solve(root, res, level);
  return res;
}