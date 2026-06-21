class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto cmp=[](pair<int,int>& a,pair<int,int>& b){
            return a.second<b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq;
        unordered_map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        for(auto it:m){
            pq.push({it.first,it.second});
        }

        vector<int> r;
        for(int i=0;i<k;i++){
            pair<int,int> a=pq.top();
            pq.pop();
            r.push_back(a.first);
        }
        return r;
    }
};