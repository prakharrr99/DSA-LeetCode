class Solution {
public:
    int solve(int amount, vector<int>& coins,int i,vector<vector<long long>>& dp){
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
        vector<vector<long long>> dp(coins.size(),vector<long long>(amount+1,-1));

        for(int i=0;i<coins.size();i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=amount;i++){
            if(i<coins[0]) dp[0][i]=0;
            else if(i%coins[0]==0) dp[0][i]=1;
            else dp[0][i]=0;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                int take_same=0;
                int no_take=dp[i-1][j];
                if(j-coins[i]>=0) take_same=dp[i][j-coins[i]];
                dp[i][j]=1LL*no_take+1LL*take_same;
            }
        }
        return dp[coins.size()-1][amount];
        return solve(amount,coins,coins.size()-1,dp);
    }
};