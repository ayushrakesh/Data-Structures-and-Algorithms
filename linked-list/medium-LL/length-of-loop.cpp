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
// Brute way using map
int lengthOfLoopBrute(Node *head)
{
  map<Node *, int> mmp;
  Node *temp = head;
  int timer = 1;

  while (temp)
  {
    if (mmp.find(temp) != mmp.end())
    {
      int value = mmp[temp];
      return timer - value;
    }
    mmp[temp] = timer;
    timer++;

    temp = temp->next;
  }
  return 0;
}
// Optimal solution  for length of a loop -> Tortoise hare algo -> O(n)
int lengthOfLoop(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  bool flag = false;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    /* code */

    if (slow == fast)
    {
      int cnt = 0;
      flag = true;
      break;
    }
  }

  if (flag)
  {
    int cnt = 1;
    slow = slow->next;
    while (slow != fast)
    {
      slow = slow->next;
      cnt++;
      /* code */
    }
    return cnt;
  }
  return 0;
}
int main()
{
  vector<int> v = {10, 1, 2, 3, 4};

  Node *head = arrayToLL(v);

  cout << head->next->next->next->next->next << endl;

  // cout << lengthOfLL(head) << endl;
  // cout << searchInLL(head, 2) << endl;
}