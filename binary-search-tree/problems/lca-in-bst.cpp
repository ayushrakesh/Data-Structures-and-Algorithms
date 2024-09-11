// /**
//  * Definition for a binary tree node.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//  */

class Solution
{
public:
  TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (!root)
      return NULL;

    if (p->val < root->val && q->val > root->val)
      return root;
    if (p->val > root->val && q->val < root->val)
      return root;
    if (p->val == root->val || q->val == root->val)
      return root;
    if (p->val < root->val && q->val < root->val)
      return solve(root->left, p, q);

    if (p->val > root->val && q->val > root->val)
      return solve(root->right, p, q);

    return NULL;
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    return solve(root, p, q);
  }
};