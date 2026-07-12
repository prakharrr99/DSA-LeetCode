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
    ListNode* mid(ListNode* head){
        if(head==NULL|| head->next==NULL) return head;
        ListNode* f=head;
        ListNode* s=head;

        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
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
    void reorderList(ListNode* head) {

        if(head==NULL || head->next==NULL || head->next->next==NULL) return ;

        ListNode* h1=head;
        ListNode* m=mid(head);
        ListNode* h2=m->next;
        m->next=NULL;

        h2=reverse(h2);

        if(h2==NULL) return ;
        
        ListNode* newhead=h1;
        ListNode* tail=newhead;

        h1=h1->next;
        tail->next=h2;
        tail=tail->next;
        h2=h2->next;

        while(h1!=NULL && h2!=NULL){
            tail->next=h1;
            h1=h1->next;
            tail=tail->next;
            tail->next=h2;
            h2=h2->next;
            tail=tail->next;
        }
        
        while(h1!=NULL){
            tail->next=h1;
            h1=h1->next;
            tail=tail->next;
        }

        while(h2!=NULL){
            tail->next=h2;
            h2=h2->next;
            tail=tail->next;
        }

        tail->next=NULL;
        head=newhead;
    }
};