class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()-1) return 0;
        if(nums[i]==0) return 1e5;
        
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            ans=min(ans,solve(nums,i+j,dp)+1);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;

        vector<int> dp(nums.size(),-1);

        dp[nums.size()-1]=0;
        for(int i=0;i<nums.size()-1;i++) if(nums[i]==0) dp[i]=1e5;
        
        int n=nums.size();
        for(int i=nums.size()-2;i>=0;i--){
            int ans=1e5;
            for(int j=1;j<=nums[i];j++){
                ans=min(ans,dp[min(n-1,i+j)]+1);
            }
            dp[i]=ans;
        }
        return dp[0];

        return solve(nums,0,dp);
    }
};