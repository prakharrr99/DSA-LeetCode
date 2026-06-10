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
    ListNode* merge(ListNode* h1,ListNode* h2){
        if(h2==NULL) return h1;
        if(h1==NULL) return h2;

        ListNode* head=NULL;
        ListNode* temp=NULL;

        if(h1->val>h2->val){
            head=h2;
            h2=h2->next;
            temp=head;
        }
        else{
            head=h1;
            h1=h1->next;
            temp=head;
        }

        while(h1!=NULL && h2!=NULL){
            if(h1->val>h2->val){
                temp->next=h2;
                h2=h2->next;
            }
            else{
                temp->next=h1;
                h1=h1->next;
            }
            temp=temp->next;
        }
        while(h1!=NULL){
            temp->next=h1;
            temp=temp->next;
            h1=h1->next;
        }
        while(h2!=NULL){
            temp->next=h2;
            temp=temp->next;
            h2=h2->next;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* temp=NULL;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        temp->next=NULL;

        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);

        return merge(l1,l2);
    }
};