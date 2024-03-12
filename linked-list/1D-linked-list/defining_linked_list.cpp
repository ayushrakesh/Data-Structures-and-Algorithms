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

int main()
{
  Node *head = new Node(2, nullptr);

  Node *sec = new Node(3, nullptr);
  head->next = sec;

  cout << head->data << endl;
  cout << sec->data << endl;
  cout << head->next << endl;
  cout << sec->next << endl;
}