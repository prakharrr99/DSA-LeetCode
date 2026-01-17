class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long s=0;
        for(auto it:nums) s+=it;
        long long r=s%p; if(r==0) return 0;
        unordered_map<int,int> m;
        s=0; int ans=INT_MAX;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            // pre.push_back(s%p);
            int need=(s%p-r+p)%p;
            if(m.find(need)!=m.end()){
                ans=min(ans,i-m[need]);
            }
            m[s%p]=i;
        }
        if(ans==INT_MAX || ans==nums.size()) return -1;
        return ans;
    }
};