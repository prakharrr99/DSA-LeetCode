class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>> pq;
    int n;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=1;i<=n-k;i++){
            pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.size()!=n){
            pq.push(val);
            return pq.top();
        }
        if(pq.top()<=val){
            pq.push(val);
            pq.pop();
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */