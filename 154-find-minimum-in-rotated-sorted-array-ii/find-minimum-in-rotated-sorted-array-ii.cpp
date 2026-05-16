class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++) ans=min(ans,nums[i]);
        return ans;
    }
};