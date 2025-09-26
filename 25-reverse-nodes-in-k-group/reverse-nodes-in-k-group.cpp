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
    int length(ListNode* head){
        int s=0;
        while(head!=NULL){
            s++;
            head=head->next;
        }
        return s;
    }
    ListNode* reverse(ListNode* head,int k){

        if(head==NULL || head->next==NULL) return head;
        if(length(head)<k) return head;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nex=curr;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        if(length(head)<k) return head;
        
        ListNode* temp=head;
        for(int i=1;i<k;i++){
            temp=temp->next;
        }
        ListNode* nex=temp->next;
        temp->next=NULL;
        head=reverse(head,k);

        ListNode* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=reverseKGroup(nex,k);
        return head;
    }
};