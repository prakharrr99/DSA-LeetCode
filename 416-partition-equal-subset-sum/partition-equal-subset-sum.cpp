class Solution {
public:
    int solve(vector<int>& nums,int n,int s,vector<vector<int>>& dp){
        if(s==0) return 1;
        if(n==0){
            if(s-nums[0]==0) return 1;
            return 0;
        }
        if(s<0) return 0;

        if(dp[n][s]!=-1) return dp[n][s];
        if(solve(nums,n-1,s-nums[n],dp)+solve(nums,n-1,s,dp)>=2) return dp[n][s]=2;
        return dp[n][s]=solve(nums,n-1,s-nums[n],dp)+solve(nums,n-1,s,dp);
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++) s+=nums[i];
        if(s&1) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(s+1,-1));
        s=s/2;
        return 2<=solve(nums,nums.size()-1,s,dp);
    }

};