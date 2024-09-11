// /**
//  * Definition for a binary tree node.
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
  int res = 1;
  int ans = 0;
  bool b = false;
  void solve(TreeNode *root, int k)
  {
    if (!root)
      return;

    solve(root->left, k);
    if (res == k && !b)
    {
      ans = root->val;
      b = true;
      return;
    }
    res++;
    solve(root->right, k);
  }
  int kthSmallest(TreeNode *root, int k)
  {
    solve(root, k);
    return ans;
  }
};