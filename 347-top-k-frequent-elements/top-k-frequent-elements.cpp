class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        int maxi=0;
        for(int i=1;i<=k;i++){
            auto iit=m.begin();
            for(auto it=m.begin();it!=m.end();it++){
                if(maxi<it->second){
                    maxi=it->second;
                    iit=it;
                }
            }
            ans.push_back(iit->first); 
            iit->second=0;
            maxi=0;
        }
        return ans;
    }
};