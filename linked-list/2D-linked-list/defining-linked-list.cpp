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
int main()
{
  Node *head = new Node(8, nullptr, nullptr);

  cout << head->data << endl;
}