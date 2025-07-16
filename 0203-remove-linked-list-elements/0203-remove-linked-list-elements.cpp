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
    ListNode* iterative(ListNode*head,int val){
        if(!head)return nullptr;
        ListNode* dummy =new ListNode(-1);
        dummy->next=head;
        ListNode*curr= dummy;
        
        while(curr->next){
            if(curr->next->val == val){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        return dummy->next;
    }
    ListNode* removeElements(ListNode* head, int val) {
       
       return iterative(head,val);
    }
};