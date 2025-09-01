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
private:
    void insertattail(ListNode*& head,ListNode*& tail,int data){
        ListNode* temp=new ListNode(data);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(list1!=NULL && list2!=NULL){
            if(list1->val > list2->val){
                insertattail(head,tail,list2->val);
                list2=list2->next;
            }
            else{
                insertattail(head,tail,list1->val);
                list1=list1->next;
            }
        }
        while(list1!=NULL){
            insertattail(head,tail,list1->val);
            list1=list1->next;
        }
        while(list2!=NULL){
            insertattail(head,tail,list2->val);
            list2=list2->next;
        }
        return head;
    }
};