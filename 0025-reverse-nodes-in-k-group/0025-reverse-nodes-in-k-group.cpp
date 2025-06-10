class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (k--) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        if (count == k) {
            ListNode* newHead = reverse(head, k);
            head->next = reverseKGroup(temp, k);
            return newHead;
        }
        return head;
    }
};