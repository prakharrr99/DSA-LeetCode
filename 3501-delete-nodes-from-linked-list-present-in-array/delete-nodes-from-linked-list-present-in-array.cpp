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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head==NULL) return head;
        unordered_set<int> s(nums.begin(),nums.end());
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* prev=dummy;
        while(prev->next!=NULL){
            if(s.find(prev->next->val)!=s.end()){
                // ListNode* del=prev->next;  // only break the link no need to delete the node 
                prev->next=prev->next->next;
                // delete del;
            }
            else{
                prev=prev->next;
            }
        }
        return dummy->next;
    }
};