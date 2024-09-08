/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  void solvepreIt(TreeNode *root, vector<int> &preorder)
  {
    if (root == NULL)
    {
      return;
    }
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
      TreeNode *node = st.top();
      preorder.push_back(st.top()->val);
      st.pop();

      // TreeNode *r = root->right;
      if (node->right != NULL)
      {
        st.push(node->right);
      }
      // TreeNode *l = root->left;
      if (node->left != NULL)
      {
        st.push(node->left);
      }
    }
  }
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> res;
    TreeNode *curr = root;

    while (curr)
    {
      if (curr->left == NULL)
      {
        res.push_back(curr->val);
        curr = curr->right;
      }
      else
      {
        TreeNode *prev = curr->left;
        while (prev->right != NULL && prev->right != curr)
        {
          prev = prev->right;
        }
        if (prev->right == curr)
        {
          prev->right = NULL;
          curr = curr->right;
        }
        else
        {
          res.push_back(curr->val);
          prev->right = curr;
          curr = curr->left;
        }
      }
    }
    return res;
  }
};