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
    pair<ListNode*,ListNode*> middle(ListNode* head){
        if(head==NULL || head->next==NULL) return {NULL,NULL};
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        if(fast!=NULL){
            slow=slow->next;
            while(head->next!=slow) head=head->next;

            return {head,slow};
        }
        while(head->next!=slow) head=head->next;
        return {head,slow};
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL){
            // delete head;
            return NULL;
        }
        pair<ListNode*,ListNode*> p=middle(head);

        p.first->next=p.second->next;
        delete p.second;
        return head;
    }
};