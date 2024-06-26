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
int lengthOfDLL(Node *head)
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
  cout << endl;
}
Node *insertInDLL(Node *head, int pos, int val)
{
  Node *newNode = new Node(val, nullptr, nullptr);
  Node *temp = head;

  int cnt = 1;

  if (pos == 1)
  {
    newNode->next = temp;
    temp->prev = newNode;
    head = newNode;
    return head;
  }

  while (cnt < pos - 1)
  {
    temp = temp->next;
    cnt++;
  }

  newNode->next = temp->next;
  newNode->prev = temp;

  if (temp->next != NULL)
  {
    temp->next->prev = newNode;
  }
  temp->next = newNode;

  return head;
}
Node *deleteInDLL(Node *head, int pos)
{
  if (pos == 1)
  {
    Node *temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    return head;
  }

  int cnt = 1;

  Node *temp = head;
  Node *temp2 = head->next;

  while (cnt < pos - 1)
  {
    temp = temp->next;
    temp2 = temp2->next;
    cnt++;
  }

  temp->next = temp2->next;

  if (temp2->next != NULL)
  {
    temp2->next->prev = temp2->next;
  }
  return head;
}

int main()
{
  vector<int> v = {8, 2, 3, 4, 9};

  Node *head = arrayToDLL(v);

  traverseDLL(head);
  cout << lengthOfDLL(head) << endl;

  // Node *newHead = deleteInDLL(head, 4);

  // traverseDLL(newHead);
  // cout << lengthOfDLL(newHead) << endl;
}
