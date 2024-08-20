#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int d)
  {
    this->data = d;
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
  inorder.push_back(root->data);
  solvein(root->right, inorder);
}
void solvepre(TreeNode *root, vector<int> &preorder)
{
  if (root == NULL)
  {
    return;
  }
  preorder.push_back(root->data);
  solvepre(root->left, preorder);
  solvepre(root->right, preorder);
}
void solvepost(TreeNode *root, vector<int> &postorder)
{
  if (root == NULL)
  {
    return;
  }
  solvepost(root->left, postorder);
  solvepost(root->right, postorder);
  postorder.push_back(root->data);
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
      level.push_back(curr->data);
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
  cout << root->data << endl;
}