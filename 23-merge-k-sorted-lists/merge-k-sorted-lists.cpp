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
    void merge(ListNode*& anshead,ListNode*& anstail,vector<ListNode*>& list){
        ListNode* curr1=list[0];
        ListNode* curr2=list[1];

        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val>curr2->val){
                if(head==NULL) head=tail=curr2;
                else{
                    tail->next=curr2;
                    tail=curr2;
                }
                curr2=curr2->next;
            }
            else{
                if(head==NULL) head=tail=curr1;
                else{
                    tail->next=curr1;
                    tail=curr1;
                }
                curr1=curr1->next;
            }
        }
        while(curr1!=NULL){
            if(head==NULL) head=tail=curr1;
            else{
                tail->next=curr1;
                tail=curr1;
            }
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            if(head==NULL) head=tail=curr2;
            else{
                tail->next=curr2;
                tail=curr2;
            }
            curr2=curr2->next;
        }
        anshead=head;
        anstail=tail;
        list.erase(list.begin());
        list.erase(list.begin());
        list.insert(list.begin(),anshead);
        return ;
    }
    void mergesort(ListNode*& anshead,ListNode*& anstail,vector<ListNode*>& list){
        if(list.size()==0) return ;
        if(list.size()==1) return ;
        merge(anshead,anstail,list);
        mergesort(anshead,anstail,list);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* anshead=NULL;
        ListNode* anstail=NULL;
        if(lists.size()==0) return anshead;
        if(lists.size()==1){
            anshead=lists[0];
            return anshead;
        }
        mergesort(anshead,anstail,lists);
        return anshead;
    }
};