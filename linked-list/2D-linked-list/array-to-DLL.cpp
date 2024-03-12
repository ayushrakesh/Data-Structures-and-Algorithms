#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data1, Node *next1, Node *prev1)
  {
    this->data = data1;
    this->next = next1;
    this->prev = prev1;
  }
};

Node *arrayToDLL(vector<int> v)
{
  Node *head = new Node(v[0], nullptr, nullptr);
  Node *mover = head;

  for (int i = 1; i < v.size(); i++)
  {
    Node *newNode = new Node(v[i], nullptr, nullptr);
    mover->next = newNode;
    newNode->prev = mover;

    mover = mover->next;
  }
  return head;
}
void traverseDLL(Node *head)
{

  Node *temp = head;

  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
int main()
{
  vector<int> v = {8, 2, 3, 4};

  Node *head = arrayToDLL(v);

  cout << head->data << endl;

  traverseDLL(head);
}