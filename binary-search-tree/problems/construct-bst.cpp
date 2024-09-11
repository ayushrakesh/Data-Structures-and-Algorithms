#include <bits/stdc++.h>
using namespace std;

// /**
//  * Definition for a binary tree node.
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
//  */
class Solution
{
public:
  TreeNode *solve(vector<int> &preorder, int l, int r, int n)
  {
    if (l > r)
      return NULL;

    TreeNode *node = new TreeNode(preorder[l]);
    int size = 0;
    for (int i = l + 1; i < n; i++)
    {
      if (preorder[i] < node->val)
      {
        size++;
      }
    }
    TreeNode *left = NULL;
    if (size > 0)
    {
      left = solve(preorder, l + 1, l + size, n);
    }
    // size=0;
    // int size2=0;
    // for (int i = l+1+size; i < n; i++) {
    //     if (preorder[i] > node->val) {
    //         size2++;
    //     }
    // }
    TreeNode *right = NULL;
    right = solve(preorder, l + size + 1, r, n);

    node->left = left;
    node->right = right;
    return node;
  }
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    return solve(preorder, 0, preorder.size() - 1, preorder.size());
  }
};