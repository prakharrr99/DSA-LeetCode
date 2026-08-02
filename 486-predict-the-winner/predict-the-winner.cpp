class Solution {
public:
    int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(i==j) return nums[i];

        if(dp[i][j]!=-1) return dp[i][j];

        int take_i=nums[i]+min(f(i+2,j,nums,dp),f(i+1,j-1,nums,dp));
        int take_j=nums[j]+min(f(i+1,j-1,nums,dp),f(i,j-2,nums,dp));

        return dp[i][j]=max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));

        int player_1=f(0,nums.size()-1,nums,dp);
        int player_2=s-player_1;

        return player_1>=player_2;
    }
};