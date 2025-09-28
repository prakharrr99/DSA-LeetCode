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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* curr=head;
        ListNode* nex=head->next;

        while(nex!=NULL){
            if(curr->val==nex->val){
                curr->next=nex->next;
                ListNode* temp=nex;
                nex=nex->next;
                delete temp;
            }
            else{
                curr=nex;
                nex=nex->next;
            }
        }
        return head;
    }
};