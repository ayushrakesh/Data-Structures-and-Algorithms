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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1p,*h1,*h2p,*h2, *finPrev;
         h1p=new ListNode(20,head);
         finPrev=h1p;
         h1=head;
         while(h1!=nullptr && h1->val<x){
            h1p=h1;
            h1=h1->next;
         }
 
        if(h1==nullptr||h1->next==nullptr){return head;}
         else{h2=h1->next; h2p=h1;}
         
         while(h2!=nullptr){
             if(h2->val<x){
                h2p->next=h2->next;
                h1p->next=h2;
                h2->next=h1;

                h1p=h2;
                h2=h2p->next;
             }
             
            else{
              h2p=h2;
              h2=h2p->next;
            }

         }

        return finPrev->next;

    }
};