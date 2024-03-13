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

Node *reverseLL(Node *head)
{
  Node *left = NULL;
  Node *mid = head;
  Node *right = NULL;

  while (mid)
  {
    /* code */
    right = mid->next;
    mid->next = left;
    left = mid;
    mid = right;
  }
  return left;
}
Node *reverseLLRecursive(Node *head)
{

  if (head == NULL | head->next == NULL)
    return head;

  Node *newhead = reverseLLRecursive(head->next);

  Node *temp = head->next;
  temp->next = head;
  head->next = NULL;

  return newhead;
}
int main()
{
  vector<int> v = {10};

  Node *head = arrayToLL(v);

  traverseLL(head);
  Node *newHead = reverseLL(head);
  traverseLL(newHead);
}