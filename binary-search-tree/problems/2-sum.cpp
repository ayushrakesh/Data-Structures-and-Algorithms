#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
  stack<TreeNode *> st1;
  stack<TreeNode *> st2;
  void func1(TreeNode *root)
  {
    // st.push(root);
    while (root)
    {
      st1.push(root);
      root = root->left;
    }
  }
  void func2(TreeNode *root)
  {
    // st.push(root);
    while (root)
    {
      st2.push(root);
      root = root->right;
    }
  }

  void next()
  {
    TreeNode *node = st1.top();
    int val = node->val;
    st1.pop();
    if (node->right)
    {
      node = node->right;
      while (node)
      {
        st1.push(node);
        node = node->left;
      }
    }
    return;
  }
  void before()
  {
    TreeNode *node = st2.top();
    int val = node->val;
    st2.pop();
    if (node->left)
    {
      node = node->left;
      while (node)
      {
        st2.push(node);
        node = node->right;
      }
    }
    return;
  }
  bool solve(int k)
  {
    TreeNode *node1 = st1.top();
    TreeNode *node2 = st2.top();

    if (node1->val == node2->val)
      return false;
    if (node1->val + node2->val == k)
      return true;
    if (node1->val + node2->val < k)
      next();
    if (node1->val + node2->val > k)
      before();

    return solve(k);
  }
  bool findTarget(TreeNode *root, int k)
  {
    func1(root);
    func2(root);
    return solve(k);
  }
};