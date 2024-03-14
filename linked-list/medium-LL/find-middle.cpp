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

Node *findMiddleBrute(Node *head)
{
  int cnt = 0;
  Node *temp = head;
  int len = lengthOfLL(head);

  while (cnt < len / 2)
  {
    temp = temp->next;
    cnt++;
  }
  return temp;
}
// Optimal approch to find middle -> O(n/2)
Node *tortoiseHair(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    /* code */
  }
  return slow;
}
int main()
{
  vector<int> v = {1, 2, 3, 4};

  Node *head = arrayToLL(v);
  // Node *mid = findMiddle(head);
  Node *mid = tortoiseHair(head);

  cout << mid->data << endl;

  // cout << lengthOfLL(head) << endl;
  // cout << searchInLL(head, 2) << endl;
}