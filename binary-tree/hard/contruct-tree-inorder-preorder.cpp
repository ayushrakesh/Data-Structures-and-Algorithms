#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
void helper(vector<int> &inorder)
{
  for (int i = 0; i < inorder.size(); i++)
  {
    mp[inorder[i]] = i;
  }
  return;
}
TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int pre1, int pre2, int in1, int in2)
{
  if (pre1 > pre2 || in1 > in2)
    return NULL;
  TreeNode *root = new TreeNode(preorder[pre1]);

  int ind = mp[preorder[pre1]];
  int size = ind - in1;

  root->left = solve(preorder, inorder, pre1 + 1, pre1 + size, in1, ind - 1);
  root->right = solve(preorder, inorder, pre1 + size + 1, pre2, ind + 1, in2);

  return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
  int n = inorder.size();
  helper(inorder);
  return solve(preorder, inorder, 0, n - 1, 0, n - 1);
}