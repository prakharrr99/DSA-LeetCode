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

        if(head==NULL || head->next==NULL) return head;

        //USE CONCATENATION --> 1st->list for smaller AND 2nd->list for larger
        ListNode* temp=head;
        ListNode* small=NULL;
        ListNode* big=NULL;
        ListNode* bighead=NULL;

        while(temp!=NULL){
            if(temp->val<x){
                if(small==NULL){
                    small=head=temp;
                }
                else{
                    small->next=temp;
                    small=temp;
                }
            }
            else{
                if(big==NULL){
                    big=bighead=temp;
                }
                else{
                    big->next=temp;
                    big=temp;
                }
            }
            temp=temp->next;
        }
        if(small!=NULL)
            small->next=bighead;
        if(big!=NULL)
        big->next=NULL;
        return head;
    }
};