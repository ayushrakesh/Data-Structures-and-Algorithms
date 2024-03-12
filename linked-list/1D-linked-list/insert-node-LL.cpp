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

Node *insertInLL(Node *head, int pos, int val)
{
  Node *newNode = new Node(val, nullptr);
  Node *mover = head;
  int cnt = 1;

  if (pos == 1)
  {
    newNode->next = head;
    head = newNode;
    return head;
  }

  while (cnt < pos - 1)
  {
    mover = mover->next;
    cnt++;
  }

  newNode->next = mover->next;
  mover->next = newNode;

  return head;
}

int main()
{
  vector<int> v = {10, 1, 2, 3, 4};

  Node *head = arrayToLL(v);
  Node *newHead = insertInLL(head, 6, 5);

  cout << newHead->next->next->next->next->next->data << endl;
}