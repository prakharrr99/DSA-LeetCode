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
    int len(ListNode* head){
        int a=0;
        while(head!=NULL){
            a++;
            head=head->next;
        }
        return a;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;

        int l=len(head);
        if(n>l) return head;

        ListNode* temp=head;
        if(n==l){
            temp=temp->next;
            return temp;
        }
        if(n==1){
            while(temp->next->next!=NULL) temp=temp->next;
            temp->next=NULL;
            return head;
        }

        ListNode* s=head;
        ListNode* f=head;
        for(int i=0;i<n;i++) f=f->next;
        while(f->next!=NULL){
            s=s->next;
            f=f->next;
        }

        s->next=s->next->next;
        return head;
    }
};