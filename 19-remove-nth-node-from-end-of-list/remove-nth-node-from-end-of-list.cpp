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
    int size(ListNode* head){
        int s=0;
        while(head!=NULL){
            s++;
            head=head->next;
        }
        return s;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length =size(head);
        if(length==1){
            ListNode* temp=head;
            delete temp;
            head=NULL;
            return head;
        }
        if(length-n==0){ // if deleting head
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode* prev=head; ListNode* nex=prev->next;
        for(int i=1;i<length-n;i++){ // we have to delete (length-n+1) th node from start
            prev=prev->next;
            nex=nex->next;
        }
        prev->next=nex->next;
        delete nex;
        return head;
    }
};