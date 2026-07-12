/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL ){
            return NULL;
        }

        Node* temp=head;
        Node* newhead=new Node(temp->val);
        Node* tail=newhead;
        
        temp=temp->next;

        while(temp!=NULL){
            Node* n=new Node(temp->val);
            tail->next=n;
            tail=tail->next;
            temp=temp->next;
        }

        unordered_map<Node*,Node*> m;
        Node* temp1=head;
        Node* temp2=newhead;

        while(temp1!=NULL){
            m[temp1]=temp2;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1=head;
        temp2=newhead;

        while(temp1!=NULL){
            temp2->random=m[temp1->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return newhead;
    }
};