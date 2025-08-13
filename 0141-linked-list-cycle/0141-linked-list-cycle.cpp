/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool brute(ListNode*head,unordered_map<ListNode*,bool>&m){
        ListNode*temp=head;
        while(temp){
            m[temp]=true;
            if(m.find(temp->next)!=m.end())return true;
            temp=temp->next;
        }
        return false;
    }
    bool hasCycle(ListNode* head) {
        // ListNode* slow = head;
        // ListNode* fast = head;

        // while (fast != NULL && fast->next != NULL) {
        //     slow = slow->next;
        //     fast = fast->next->next;

        //     if (slow == fast)
        //         return true;
        //     /* code */
        // }
        // return false;
        unordered_map<ListNode*,bool> m;
        return brute(head,m);
    }
};