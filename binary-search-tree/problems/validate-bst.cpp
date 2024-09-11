// /**
//  * Definition for a binary tree node.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                     right(right) {}
};
class Solution
{
public:
  long long d = LONG_MIN;
  bool b = true;
  void solve(TreeNode *root)
  {
    if (!root)
      return;

    solve(root->left);
    if (root->val <= d)
    {
      b = false;
      return;
    }
    d = root->val;
    solve(root->right);
  }
  bool isValidBST(TreeNode *root)
  {
    solve(root);
    return b;
  }
};