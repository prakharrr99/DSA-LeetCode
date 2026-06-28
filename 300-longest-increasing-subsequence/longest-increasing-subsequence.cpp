class Solution {
public:
    int f(vector<int>& nums,int i,int last,vector<vector<int>>& dp){
        if(i==nums.size()) return 0;

        int take=0;
        int not_take=f(nums,i+1,last,dp);

        if(dp[i][last+1]!=-1) return dp[i][last+1];
        if(last==-1 || nums[i]>nums[last]){
            take=f(nums,i+1,i,dp)+1;
        }

        return dp[i][last+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {

        //COORINATE CHANGE  -1->0 ,0->1 ,1->2, 2->3


        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));

        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int not_take=dp[i+1][j+1];
                int take=0;
                if(j==-1 || nums[i]>nums[j]){
                    take=dp[i+1][i+1]+1;
                }
                dp[i][j+1]=max(take,not_take);
            }
        }
        return dp[0][0];



        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));

        return f(nums,0,-1,dp);
    }
};