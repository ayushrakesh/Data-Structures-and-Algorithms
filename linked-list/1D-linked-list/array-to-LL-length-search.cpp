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

int lengthOfLL(Node *head)
{
  int count = 0;
  Node *temp = head;

  while (temp)
  {
    count++;
    temp = temp->next;
  }
  return count;
}
bool searchInLL(Node *head, int val)
{
  Node *temp = head;

  while (temp)
  {
    /* code */
    if (temp->data == val)
      return true;
    else
      temp = temp->next;
  }
  return false;
}
int main()
{
  vector<int> v = {10, 1, 2, 3, 4};

  Node *head = arrayToLL(v);

  cout << head->data << endl;

  cout << lengthOfLL(head) << endl;
  cout << searchInLL(head, 2) << endl;
}