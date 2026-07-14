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
        ListNode* p=NULL;
        ListNode* c=head;
        ListNode* n=head;
       
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        if(length(head)<k) return head;

        ListNode* temp=head;
        for(int i=0;i<k-1 ;i++){
            temp=temp->next;
        }
        ListNode* nex=temp->next;
        temp->next=NULL;
        head=reverse(head,k);
       
        ListNode* tail=head;
        while(tail->next!=NULL) tail=tail->next;
        tail->next=reverseKGroup(nex,k);
        return head;
    }
};