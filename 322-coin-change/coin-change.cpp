class Solution {
public:
    int solve(vector<int>& coins, int amount,int i,vector<vector<int>>& dp){
        if(amount<0) return 1e5;
        if(amount==0) return 0;
        if(i==0){
            if(amount<coins[i]) return 1e5;
            else if(amount%coins[i]==0) return amount/coins[0];
            return 1e5;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        int take_same=1e5;
        int take_diff=1e5;
        if(amount-coins[i]>=0) take_same=solve(coins,amount-coins[i],i,dp)+1;
        if(amount-coins[i]>=0) take_diff=solve(coins,amount-coins[i],i-1,dp)+1;
        int no_take=solve(coins,amount,i-1,dp);

        return dp[i][amount]=min(take_same,min(take_diff,no_take));
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));

        for(int i=0;i<coins.size();i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=amount;i++){
            if(i<coins[0]) dp[0][i]=1e5;
            else if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e5;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                int take_same=1e5;
                int take_diff=1e5;
                if(j-coins[i]>=0) take_same=dp[i][j-coins[i]]+1;
                if(j-coins[i]>=0) take_diff=dp[i-1][j-coins[i]]+1;
                int no_take=dp[i-1][j];

                dp[i][j]=min(take_same,min(take_diff,no_take));
            }
        }
        if(dp[coins.size()-1][amount]==1e5) return -1;
        return dp[coins.size()-1][amount];

        int a=solve(coins,amount,coins.size()-1,dp);
        if(a==1e5) return -1;
        return a;
    }
};