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
    ListNode* reverseLL(ListNode* head) {
        ListNode* left = NULL;
        ListNode* mid = head;
        ListNode* right = NULL;

        while (mid) {
            /* code */
            right = mid->next;
            mid->next = left;
            left = mid;
            mid = right;
        }
        return left;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            /* code */
        }

        ListNode* newhead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newhead;

        while (second != NULL) {
            /* code */
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};