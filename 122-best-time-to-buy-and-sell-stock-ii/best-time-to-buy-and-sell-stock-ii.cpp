class Solution {
public:
    int f(vector<int>& prices,int i,int buy,vector<vector<int>>& dp){

        if(i==prices.size()-1){
            if(buy){
                return 0;
            }
            else return prices[prices.size()-1];
        }

        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+f(prices,i+1,0,dp),0+f(prices,i+1,1,dp));
        }
        else{
            return dp[i][buy]=max(prices[i]+f(prices,i+1,1,dp),0+f(prices,i+1,0,dp));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        dp[prices.size()-1][1]=0;
        dp[prices.size()-1][0]=prices[prices.size()-1];

        for(int i=prices.size()-2;i>=0;i--){
            dp[i][0]=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);

            dp[i][1]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
        }
        return dp[0][1];
        return f(prices,0,1,dp);
    }
};