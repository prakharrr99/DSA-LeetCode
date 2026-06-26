class Solution {
public:
    int f(vector<int>& prices,int i,int buy,int t,vector<vector<vector<int>>>& dp){
        if(t==2) return 0;

        if(i==prices.size()) return 0;

        if(dp[i][buy][t]!=-1) return dp[i][buy][t];
        if(buy){
            return dp[i][buy][t]=max(-prices[i]+f(prices,i+1,0,t,dp),0+f(prices,i+1,1,t,dp));
        }
        else{
            return dp[i][buy][t]=max(prices[i]+f(prices,i+1,1,t+1,dp),0+f(prices,i+1,0,t,dp));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,0,1,0,dp);
    }
};