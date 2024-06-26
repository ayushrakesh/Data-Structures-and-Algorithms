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

Node *aggregateOddEven(Node *head)
{
  Node *odd = head->next;
  Node *even = head->next->next;

  while (even != NULL && even->next != NULL)
  {
    Node *newOdd = new Node(odd->data, nullptr);
    odd->next = newOdd;

    Node *newEven = new Node(even->data, nullptr);
    even->next = newEven;

    odd = odd->next->next;
    even = even->next->next;
    }
}

int main()
{
  vector<int> v = {10, 1, 2, 3, 4};

  Node *head = arrayToLL(v);

  cout << head->data << endl;

  cout << lengthOfLL(head) << endl;
  cout << searchInLL(head, 2) << endl;
}