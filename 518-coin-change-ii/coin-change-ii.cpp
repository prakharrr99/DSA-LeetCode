class Solution {
public:
    int solve(int amount, vector<int>& coins,int i,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i==0){
            if(amount<coins[0]) return 0;
            else if(amount%coins[0]==0) return 1;
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        int take_same=0;
        
        if(amount-coins[i]>=0) take_same=solve(amount-coins[i],coins,i,dp);
        int no_take=solve(amount,coins,i-1,dp);
        
        return dp[i][amount]=take_same+no_take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(amount,coins,coins.size()-1,dp);
    }
};