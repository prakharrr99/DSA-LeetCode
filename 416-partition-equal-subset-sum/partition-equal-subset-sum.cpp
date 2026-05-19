class Solution {
public:
    int solve(vector<int>& nums,int i,int target,vector<vector<int>>& dp){
        if(target==0) return 1;
        if(target<0) return 0;
        if(i==0){
            if(target==nums[i]) return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        if(solve(nums,i-1,target-nums[i],dp)+solve(nums,i-1,target,dp)>=2) return dp[i][target]=2;
        return dp[i][target]=solve(nums,i-1,target-nums[i],dp)+solve(nums,i-1,target,dp);
    }
    bool canPartition(vector<int>& nums) {

        int s=0;
        for(int i=0;i<nums.size();i++) s+=nums[i];
        if(s&1) return false;

        vector<vector<int>> dp(nums.size(),vector<int>(s,-1));

        return solve(nums,nums.size()-1,s/2,dp)>=2;

    }
};