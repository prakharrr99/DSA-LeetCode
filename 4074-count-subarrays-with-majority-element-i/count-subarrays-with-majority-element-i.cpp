class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            int len=0;
            unordered_map<int,int> m;
            for(int j=i;j<n;j++){
                m[nums[j]]++;
                len++;
                if(m[target]>len/2) ans++;
            }
            
        }
        return ans;
    }
};