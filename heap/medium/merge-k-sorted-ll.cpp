#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  struct Compare
  {
    bool operator()(ListNode *a, ListNode *b)
    {
      return a->val > b->val; // Min-heap (reverse order)
    }
  };
  ListNode *solve(vector<ListNode *> &lists)
  {
    priority_queue<ListNode *, vector<ListNode *>, Compare> p;

    int k = lists.size();
    for (int i = 0; i < k; i++)
      if (lists[i])
      {
        p.push(lists[i]);
      }

    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (!p.empty())
    {
      ListNode *node = p.top();
      p.pop();

      if (head == NULL)
      {
        head = node;
        tail = node;
      }
      else
      {
        tail->next = node;
        tail = node;
      }
      if (node->next)
      {
        p.push(node->next);
        node = node->next;
      }
    }
    return head;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) { return solve(lists); }
};