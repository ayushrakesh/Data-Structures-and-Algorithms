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
class BSTIterator
{
public:
  stack<TreeNode *> st;
  BSTIterator(TreeNode *root)
  {
    // st.push(root);
    while (root)
    {
      st.push(root);
      root = root->left;
    }
  }

  int next()
  {
    TreeNode *node = st.top();
    int val = node->val;
    st.pop();
    if (node->right)
    {
      node = node->right;
      while (node)
      {
        st.push(node);
        node = node->left;
      }
    }
    return val;
  }

  bool hasNext()
  {
    if (st.empty())
      return false;
    return true;
  }
};