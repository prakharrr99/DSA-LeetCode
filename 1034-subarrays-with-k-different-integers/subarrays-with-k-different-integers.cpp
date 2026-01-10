class Solution {
private:
    int solve(vector<int>& nums, int k){
        int i=0; int j=0; int ans=0;
        unordered_map<int,int> m;
        while(j<nums.size()){
            m[nums[j]]++;
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0) m.erase(nums[i]);
                i++;
            }
            if(m.size()<=k) ans+=(j-i+1);
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int p=solve(nums,k);
        int q=solve(nums,k-1);
        return p-q;
    }
};