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

int solve(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int l = solve(root->left);
  int r = solve(root->right);
  return max(l, r) + 1;
}
int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  // root->left->left->left = new TreeNode(4);
  // root->left->left->right = new TreeNode(4);
  // TreeNode* root=new TreeNode(5);
  // TreeNode* root=new TreeNode(6);
  cout << solve(root) << endl;
  // cout << isBalanced(NULL) << endl;
}