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
    void insertattail(Node*& head,Node*& tail,int data){
        Node* temp=new Node(data);
        if(head==NULL) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    Node* revert(Node* h1,Node* h2){
        Node* temp=h1;
        Node* temp2=h1;
        while(temp!=NULL){
            temp2=temp->next;
            temp->next=h2;
            temp=h2;
            h2=h2->next;
            temp->next=temp2;
            temp=temp2;
        }
        return h1;
    }
    Node* copyRandomList(Node* head) {
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        
        Node* temp=head;
        while(temp!=NULL){  // CREATING THE NEW NODE
            insertattail(clonehead,clonetail,temp->val);
            temp=temp->next;
        }

        Node* modified=revert(head,clonehead); // MODIFYING THE LIST

        while(modified!=NULL){
            if(modified->random==NULL) modified->next->random=NULL; 
            else modified->next->random=modified->random->next;
            modified=modified->next->next;
        }

        temp=head;// REVERTING THE CHANGES
        while(temp!=NULL){
            modified=temp->next;
            if(temp->next==NULL) temp->next=NULL;
            else temp->next=temp->next->next;
            temp=modified;
        }
        return clonehead;
    }
};