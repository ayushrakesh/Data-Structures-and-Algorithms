#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data1, Node *next1)
  {
    this->data = data1;
    this->next = next1;
  }
};
Node *arrayToLL(vector<int> &v)
{
  Node *head = new Node(v[0], nullptr);
  Node *mover = head;

  for (int i = 1; i < v.size(); i++)
  {
    Node *newNode = new Node(v[i], nullptr);
    mover->next = newNode;
    mover = mover->next;
  }
  return head;
}
void traverseLL(Node *head)
{
  Node *temp = head;

  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
void *deleteNodeLL(Node *node)
{
  node->data = node->next->data;
  node->next = node->next->next;

  return 0;
}

int main()
{
  vector<int> v = {0, 8, 2, 3, 4};

  Node *head = arrayToLL(v);
  // Node *newHead = insertInLL(head, 6, 5);

  // cout << newHead->next->next->next->next->next->data << endl;

  traverseLL(head);
  deleteNodeLL(head->next->next);
  traverseLL(head);

  cout << head->data << endl;
}