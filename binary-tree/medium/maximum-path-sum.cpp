#include <bits/stdc++.h>
using namespace std;

int solve(TreeNode *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int l = solve(root->left);
  int r = solve(root->right);

  int t = l + r + root->val;
  int maxi = max(r, l);
  // maxi = max(maxi, r);
  int u = root->val + l;
  int v = root->val + r;
  maxi = max(maxi, u);
  maxi = max(maxi, v);
  maxi = max(maxi, t);
  return maxi;
}
int maxPathSum(TreeNode *root)
{
  int maxi = 0;
  return solve(root);
  // return maxi;
}

int main()
{
}