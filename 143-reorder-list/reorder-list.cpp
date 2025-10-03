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
    void reorderList(ListNode* head) {
        
        if(head==NULL || head->next==NULL || head->next->next==NULL) return;
        ListNode* temp=head;
        ListNode* temp2=head;
        ListNode* temp3=head;

        while(temp2->next->next!=NULL){ // EK BAAR REORDER KIYA
            temp2=temp2->next;
        }
        temp3=temp2;
        temp2=temp2->next;
        temp3->next=NULL;

        temp2->next=temp->next;
        temp->next=temp2;

        temp2=temp2->next;
        temp=temp2;
        reorderList(temp2);
        return;
    }
};