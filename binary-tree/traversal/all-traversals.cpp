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

void solvein(TreeNode *root, vector<int> &inorder)
{
  if (root == NULL)
  {
    return;
  }
  solvein(root->left, inorder);
  inorder.push_back(root->val);
  solvein(root->right, inorder);
}
void solveinIt(TreeNode *root, vector<int> &inorder)
{
  if (root == NULL)
  {
    return;
  }
  stack<TreeNode *> st;
  while (true)
  {
    TreeNode *node = st.top();
    if (node != NULL)
    {
      st.push(node);
      node = node->left;
    }
    else
    {
      if (!st.empty())
      {
        node = st.top();
        st.pop();
        inorder.push_back(node->val);
        node = node->right;
      }
    }
  }
}
void solvepre(TreeNode *root, vector<int> &preorder)
{
  if (root == NULL)
  {
    return;
  }
  preorder.push_back(root->val);
  solvepre(root->left, preorder);
  solvepre(root->right, preorder);
}
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
void solvepost(TreeNode *root, vector<int> &postorder)
{
  if (root == NULL)
  {
    return;
  }
  solvepost(root->left, postorder);
  solvepost(root->right, postorder);
  postorder.push_back(root->val);
}
void solvepostIt(TreeNode *root, vector<int> &postorder)
{
  if (root == NULL)
    return;
  stack<TreeNode *> st1, st2;
  st1.push(root);

  while (!st1.empty())
  {
    root = st1.top();
    st1.pop();
    st2.push(root);

    if (root->left != NULL)
      st1.push(root->left);
    if (root->right != NULL)
      st1.push(root->right);
  }

  while (!st2.empty())
  {
    /* code */
    postorder.push_back(st2.top()->val);
    st2.pop();
  }
}
vector<int> postorderTraversal(TreeNode *root)
{
  vector<int> postorder;
  solvepostIt(root, postorder);
  return postorder;
}
void bfs(TreeNode *root, vector<vector<int>> &res)
{
  queue<TreeNode *> que;
  if (root == NULL)
    return;
  que.push(root);

  while (!que.empty())
  {
    vector<int> level;
    int size = que.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = que.front();
      que.pop();

      if (curr->left != NULL)
      {
        que.push(curr->left);
      }
      if (curr->right != NULL)
      {
        que.push(curr->right);
      }
      level.push_back(curr->val);
    }
    res.push_back(level);
  }
}
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
  // Write your code here.
  vector<vector<int>> res;
  vector<int> inorder;
  vector<int> preorder;
  vector<int> postorder;

  solvein(root, inorder);
  res.push_back(inorder);

  solvepre(root, preorder);
  res.push_back(preorder);

  solvepost(root, postorder);
  res.push_back(postorder);
  return res;
}
int main()
{
  TreeNode *root = new TreeNode(1);
  cout << root->val << endl;
}