class Solution {
public:
    class cmp {
    public:
        bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) const {
            if(a.second != b.second)
                return a.second < b.second;

            return a.first > b.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

        for(auto it:m){
            pq.push({it.first,it.second});
        }

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};