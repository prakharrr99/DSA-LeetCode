class Solution {
public:
    bool solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()-1) return true;
        if(nums[i]==0) return false;
        
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(solve(nums,i+j,dp)) return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;

        vector<int> dp(nums.size(),-1);

        dp[nums.size()-1]=1;
        for(int i=0;i<nums.size();i++) if(nums[i]==0) dp[i]=0;

        for(int i=nums.size()-2;i>=0;i--){
            int a=0;
            for(int j=1;j<=nums[i];j++){
                if(i+j>=nums.size()-1 || dp[i+j]){
                    a=1;
                    break;
                }
            }
            dp[i]=a;
        }
        return dp[0];
        return solve(nums,0,dp);
    }
};