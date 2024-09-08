#include <bits/stdc++.h>
using namespace std;

void markParent(TreeNode *root,
                unordered_map<TreeNode *, TreeNode *> &parent)
{
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode *node = q.front();
      q.pop();
      if (node->left)
      {
        q.push(node->left);
        parent[node->left] = node;
      }
      if (node->right)
      {
        q.push(node->right);
        parent[node->right] = node;
      }
    }
  }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
  unordered_map<TreeNode *, TreeNode *> parent;
  unordered_map<TreeNode *, bool> visited;
  queue<TreeNode *> q;
  vector<int> res;

  markParent(root, parent);
  q.push(target);
  visited[target] = true;
  int level = 0;

  while (!q.empty())
  {
    int size = q.size();
    if (level == k)
      break;
    level++;
    for (int i = 0; i < size; i++)
    {
      TreeNode *node = q.front();
      q.pop();

      if (node->left && !visited[node->left])
      {
        q.push(node->left);
        visited[node->left] = true;
      }
      if (node->right && !visited[node->right])
      {
        q.push(node->right);
        visited[node->right] = true;
      }
      if (parent[node] && !visited[parent[node]])
      {
        q.push(parent[node]);
        visited[parent[node]] = true;
      }
    }
  }

  while (!q.empty())
  {
    res.push_back(q.front()->val);
    q.pop();
  }
  return res;
}
int minTime(Node *root, int target)
{
  // Your code goes here
}