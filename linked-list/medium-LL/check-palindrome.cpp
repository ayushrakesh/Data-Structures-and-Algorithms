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
// Using map -> check Palindrome
bool checkPalindromeBrute(Node *head)
{
  stack<int> st;
  Node *temp = head;

  while (temp)
  {
    /* code */
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;

  while (temp)
  {
    if (temp->data != st.top())
      return false;
    else
    {
      st.pop();
      temp = temp->next;
    }
  }
  return true;
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
// Optimal approach - O(n),O(1)
bool checkPalindrome(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    /* code */
  }

  Node *newhead = reverseLL(slow->next);
  Node *first = head;
  Node *second = newhead;

  while (second != NULL)
  {
    /* code */
    if (first->data != second->data)
    {
      Node *temp = reverseLL(newhead);
      return false;
    }
    first = first->next;
    second = second->next;
  }

  Node *temp = reverseLL(newhead);

  return true;
}
int main()
{
  vector<int> v = {1, 2};

  Node *head = arrayToLL(v);

  // cout << head->data << endl;

  // cout << lengthOfLL(head) << endl;
  // cout << searchInLL(head, 2) << endl;

  cout << checkPalindrome(head) << endl;
}