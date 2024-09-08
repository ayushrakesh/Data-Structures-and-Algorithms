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
TreeNode *solve(vector<int> &postorder, vector<int> &inorder, int post1,
                int post2, int in1, int in2)
{
  if (post1 > post2 || in1 > in2)
    return NULL;
  TreeNode *root = new TreeNode(postorder[post2]);

  int ind = mp[postorder[post2]];
  int size = ind - in1;

  root->left =
      solve(postorder, inorder, post1, post1 + size - 1, in1, ind - 1);
  root->right =
      solve(postorder, inorder, post1 + size, post2 - 1, ind + 1, in2);

  return root;
}