class Solution {
public:
    int solve(vector<vector<int>>& coins,int m,int n,int k,vector<vector<vector<int>>>& dp){
        if(n<0 || m<0) return -1e9;
        if(m==0 && n==0){
            if(coins[0][0]>=0) return coins[0][0]; 
            else if(k>0) return 0;
            else return coins[0][0];
        }
        if(dp[m][n][k]!=INT_MIN) return dp[m][n][k];
        int curr=coins[m][n];
        int neutralise=-1e9;
        if(curr<0 && k>0){
            neutralise=max(solve(coins,m-1,n,k-1,dp),solve(coins,m,n-1,k-1,dp));
        }
        int not_neutralise=max(solve(coins,m-1,n,k,dp)+curr,curr+solve(coins,m,n-1,k,dp));
        return dp[m][n][k]=max(not_neutralise,neutralise);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        
        vector<vector<vector<int>>> dp(coins.size(),vector<vector<int>>(coins[0].size(),vector<int>(3,INT_MIN)));
       
        return solve(coins,coins.size()-1,coins[0].size()-1,2,dp);
    }
};