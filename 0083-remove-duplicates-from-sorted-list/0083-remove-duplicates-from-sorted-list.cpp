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
    ListNode* solve(ListNode*head){
        if(!head || head->next==NULL)return head;

        ListNode* curr=head;
        ListNode*next=head->next;

        while(curr->next){
            if(curr->val == next->val){
                ListNode*temp=next->next;
                curr->next=temp;
                next=temp;
            }else{
                curr=curr->next;
                next=next->next;
            }
        }
        return head;
    }
    ListNode* recursive(ListNode*head){
        if(!head)return nullptr;
        if(head->next==NULL)return head;

        ListNode*newhead= recursive(head->next);
        if(newhead->val==head->val){
            head->next=newhead->next;
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        // return solve(head);
        return recursive(head);
    }
};