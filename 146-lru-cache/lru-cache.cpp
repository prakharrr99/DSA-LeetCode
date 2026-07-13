class Node{
    public:
    Node* next;
    Node* prev;
    int val;
    int key;

    Node(int k,int v){
        key=k;
        val=v;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    int n;
    unordered_map<int,Node*> m;
    Node* head=NULL;
    Node* tail=NULL;
    LRUCache(int capacity) {
        n=capacity;
    }
    void insertathead(Node*& temp){
        if(temp==NULL) return ;
        if(head==NULL){
            head=tail=temp;
            return;
        }
        head->prev=temp;
        temp->next=head;
        temp->prev=NULL;
        head=temp;
    }
    void deleteNode(Node*& temp){
        if(temp==NULL) return ;
        if(temp==tail && tail==head){
            tail=NULL;
            head=NULL;
            return;
        }
        if(temp==head){
            head=head->next;
            head->prev=NULL;
            return;
        }
        if(temp==tail){
            tail=tail->prev;
            tail->next=NULL;
            temp->prev=NULL;
            return ;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->prev=temp->next=NULL;
    }
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        
        Node* temp=m[key];
        deleteNode(temp);
        insertathead(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* temp2=m[key];
            temp2->val=value;
            deleteNode(temp2);
            insertathead(temp2);
            return;
        }
        Node* temp3=new Node(key,value);
        m[key]=temp3;
        if(n==0){
            m.erase(tail->key);
            Node* temp4=tail;
            deleteNode(temp4);
            delete temp4;
        }
        else n--;
        insertathead(temp3);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */