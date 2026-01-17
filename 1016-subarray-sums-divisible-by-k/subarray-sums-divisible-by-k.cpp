class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        long long s=0;
        unordered_map<int,int> m;
        m[0]=1; 
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            int need=(s%k+k)%k;
            ans+=m[need];
            m[need]++;
        }
        return ans;
    }
};