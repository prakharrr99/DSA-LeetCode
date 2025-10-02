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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;

        if(head->next==head) return head;

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL && slow!=fast){
            slow=slow->next;
            fast=fast->next->next;
        }
        if( fast==NULL ||fast->next==NULL ) return NULL;
        slow=head;
        while(fast->next!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};