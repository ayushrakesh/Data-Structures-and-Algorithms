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
int ans = 0;
int brute(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int l = brute(root->left);
  int r = brute(root->right);

  // int maxi = max(l, r) + 1;
  return max(l, r) + 1;
}
int optimal(TreeNode *root, int &maxi)
{
  if (root == NULL)
    return 0;

  int l = optimal(root->left, maxi);
  int r = optimal(root->right, maxi);

  maxi = max(maxi, l + r);
  return 1 + max(l, r);
}
void diameterOfBinaryTree(TreeNode *root, int &maxi)
{
  if (root == NULL)
    return;

  int l = solve(root->left);
  int r = solve(root->right);

  maxi = max(maxi, l + r);
  diameterOfBinaryTree(root->left, maxi);
  diameterOfBinaryTree(root->right, maxi);
}
int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->left->right = new TreeNode(5);
  // root->left->left->left = new TreeNode(4);
  // root->left->left->right = new TreeNode(4);
  // TreeNode* root=new TreeNode(5);
  // TreeNode* root=new TreeNode(6);
  int maxi = 0;
  diameterOfBinaryTree(root, maxi);
  cout << maxi << endl;
  // cout << isBalanced(NULL) << endl;
}