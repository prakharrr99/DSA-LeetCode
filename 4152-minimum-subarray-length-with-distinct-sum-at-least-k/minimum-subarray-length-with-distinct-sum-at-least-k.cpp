class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        unordered_map<int,int> m;
        int sum=0;
        int ans=INT_MAX;
        while(j<nums.size()){
            m[nums[j]]++;
            if(m[nums[j]]==1){
                sum+=nums[j];
            }
            while(sum>=k){
                ans=min(ans,j-i+1);
                m[nums[i]]--;
                if(m[nums[i]]==0) sum-=nums[i];
                i++;
            }
            j++;
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};