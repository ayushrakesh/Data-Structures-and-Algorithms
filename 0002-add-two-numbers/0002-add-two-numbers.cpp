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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* add = NULL;
        ListNode* prev = NULL;

        while (a && b) {
            ListNode* newnode = new ListNode(0);
            int c = (a->val + b->val + carry);
            if (c >= 10) {
                newnode->val = c % 10;
                carry = 1;
            } else {
                newnode->val = c;
                carry=0;
            }
            if (add == NULL)
                add = newnode;
            if (prev == NULL) {
                prev = newnode;
            } else {
                prev->next = newnode;
                prev = newnode;
            }
            a = a->next;
            b = b->next;
        }

        while (a) {
            ListNode* newnode = new ListNode(0);
            int c = (a->val + carry);
            if (c >= 10) {
                newnode->val = c % 10;
                carry = 1;
            } else {
                newnode->val = c;
                carry=0;
            }
            if (add == NULL)
                add = newnode;
            if (prev == NULL) {
                prev = newnode;
            } else {
                prev->next = newnode;
                prev = newnode;
            }
            a = a->next;
        }
        while (b) {
            ListNode* newnode = new ListNode(0);
            int c = (b->val + carry);
            if (c >= 10) {
                newnode->val = c % 10;
                carry = 1;
            } else {
                newnode->val = c;
                carry=0;
            }
            if (add == NULL)
                add = newnode;
            if (prev == NULL) {
                prev = newnode;
            } else {
                prev->next = newnode;
                prev = newnode;
            }
            b = b->next;
        }
        if (carry) {
            ListNode* newnode = new ListNode(1);
            prev->next = newnode;
            newnode->next = NULL;
        }
        return add;
    }
};