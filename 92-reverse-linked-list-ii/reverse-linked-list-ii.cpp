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
    ListNode* reverseBetween(ListNode* head, int left, int right){

        if(head==NULL || head->next==NULL) return head;

        ListNode* prev=NULL;
        ListNode* curr=head;

        for(int i=1;i<left;i++){
            prev=curr;
            curr=curr->next;
        }

        ListNode* stop=curr;
        for(int i=0;i<right-left;i++){
            stop=stop->next;
        }
        stop=stop->next;

        ListNode* nex=curr;
        ListNode* reverseprev=NULL;
        ListNode* store=curr;
        while(curr!=stop){
            nex=curr->next;
            curr->next=reverseprev;
            reverseprev=curr;
            curr=nex;
        }
        if(left!=1){
            prev->next=reverseprev;
        }
        if(left==1){
            head=reverseprev;
        }
        store->next=stop;
        return head;

    }
};