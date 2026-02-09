class FrontMiddleBackQueue {
public:
    deque<int> q;
    int mid=0;
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        q.push_front(val); 
        mid=q.size()/2;
    }
    
    void pushMiddle(int val) {
        q.push_back(val);
        for(int i=q.size()-1;i>=0 && i>mid;i--){
            swap(q[i],q[i-1]);
        }
        mid=q.size()/2;
    }
    
    void pushBack(int val) {
        q.push_back(val);
        mid=q.size()/2;
    }
    
    int popFront() {
        if(q.size()==0) return -1;
        int r=q.front();
        q.pop_front();
        mid=q.size()/2;
        return r;
    }
    
    int popMiddle() {
        if(q.size()==0) return -1;
        mid=(q.size()-1)/2;
        int r=q[mid];
        for(int i=mid;i<q.size()-1;i++){
            swap(q[i],q[i+1]);
        }
        q.pop_back();
        return r;
    }
    
    int popBack() {
        if(q.size()==0) return -1;
        int r=q.back();
        q.pop_back();
        mid=q.size()/2;
        return  r;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */