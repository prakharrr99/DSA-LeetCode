class MinStack {
public:
    stack<int> st;
    stack<int> m;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(m.empty() || m.top()>=value) m.push(value);
    }
    
    void pop() {
        if(!st.empty()){
            int a=st.top();
            if(m.top()==st.top()) m.pop();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */