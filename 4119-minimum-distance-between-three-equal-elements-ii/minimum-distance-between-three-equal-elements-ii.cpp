class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,set<int>> m;

        int ans=INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                if(m[nums[i]].size()==2){
                    auto it=m[nums[i]].begin();
                    int j=*(it);
                    it++;
                    int k=*(it);
                    ans=min(ans,abs(i-j)+abs(j-k)+abs(k-i));
                }
            }
            if(m[nums[i]].size()==2) m[nums[i]].erase(m[nums[i]].begin());
            m[nums[i]].insert(i);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
