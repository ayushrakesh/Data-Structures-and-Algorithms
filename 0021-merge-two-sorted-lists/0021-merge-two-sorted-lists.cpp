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
    ListNode* solve(ListNode* a, ListNode* b) {
        if (!a)
            return b;
        if (!b)
            return a;

        ListNode* i = a;
        ListNode* j = b;
        ListNode* newhead = NULL;
        ListNode* temp = NULL;

        while (i && j) {
            ListNode*newnode=NULL;

            if (i->val <= j->val) {
                 newnode = new ListNode(i->val);
                 i=i->next;
            } else {
                 newnode = new ListNode(j->val);
                 j=j->next;
            }
            if (newhead == NULL) {
                newhead = newnode;
                temp = newnode;
            } else {
                temp->next = newnode;
                temp=newnode;
            }
        }

        while(i){
            ListNode*newnode=new ListNode(i->val);
            temp->next=newnode;
            temp=newnode;
            i=i->next;
        }
        while(j){
            ListNode*newnode=new ListNode(j->val);
            temp->next=newnode;
            temp=newnode;
            j=j->next;
        }
        return newhead;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return solve(list1, list2);
    }
};