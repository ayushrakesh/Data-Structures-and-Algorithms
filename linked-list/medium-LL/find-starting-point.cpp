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
bool isCycle(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next;

    if (slow = fast)
      return true;
    /* code */
  }
  return false;
}
// Finding starting point of cycle -> if not return null -> using map
Node *findStartingPoint(Node *head)
{
  map<Node *, int> mmp;

  Node *temp = head;

  while (temp)
  {
    if (mmp.find(temp) != mmp.end())
      return temp;
    mmp[temp] = 1;
    temp = temp->next;
  }
  return NULL;
}
// Tortoise - Hare algorithm
Node *findStartingPointMehtod2(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      slow = head;
      while (slow != fast)
      {
        slow = slow->next;
        fast = fast->next;
        /* code */
      }
      return slow;
    }
    /* code */
  }
  return NULL;
}
int main()
{
  vector<int> v = {10, 1, 2, 3, 4};

  Node *head = arrayToLL(v);

  cout << head->data << endl;

  cout << lengthOfLL(head) << endl;
  cout << searchInLL(head, 2) << endl;
}