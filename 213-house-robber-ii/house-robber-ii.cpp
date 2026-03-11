class Solution {
public:
    int solve(int id,vector<int>& nums,vector<int>& dp){
        if(id==0) return nums[id];
        if(id<0) return 0;

        if(dp[id]!=-1) return dp[id];

        int take=solve(id-2,nums,dp)+nums[id];

        int notake=solve(id-1,nums,dp);

        return dp[id]=max(take,notake);
    }
    int rob(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];

        vector<int> dp(nums.size(),-1);
        vector<int> dp1(nums.size(),-1);

        vector<int> temp1,temp2;

        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }

        return max(solve(temp1.size()-1,temp1,dp),solve(temp2.size()-1,temp2,dp1));
    }
};