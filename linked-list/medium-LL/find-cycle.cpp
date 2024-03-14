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

bool isCycleBrute(Node *head)
{
  map<Node *, int> mmp;
  Node *temp = head;

  while (temp)
  {
    if (mmp.find(temp) != mmp.end())
    {
      return true;
    }
    mmp[temp] = 1;

    temp = temp->next;
  }
  return false;
}
bool isCycle(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      return true;
    /* code */
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