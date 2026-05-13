class Solution {
public:
    int solve(int id,vector<int>& nums,vector<int>& dp){
        if(id==nums.size()-1 ){
            return nums[id];
        }
        if(id>=nums.size()) return 0;
        
        if(dp[id]!=-1) return dp[id];

        int pick=solve(id+2,nums,dp)+nums[id];

        int notpick=solve(id+1,nums,dp);

        return dp[id]=max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);

        return solve(0,nums,dp);
    }
};