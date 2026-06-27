class Solution {
public:
    int f(vector<int>& prices,int i,int buy,int fee,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+f(prices,i+1,0,fee,dp),0+f(prices,i+1,1,fee,dp));
        }
        return dp[i][buy]=max(prices[i]+f(prices,i+1,1,fee,dp)-fee,0+f(prices,i+1,0,fee,dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        //SPACE OPTIMIZATION
       
        vector<int> next(2,0);
        vector<int> curr(2,0);
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1){
                   curr[j]=max(-prices[i]+next[0],0+next[1]);
                }
                else curr[j]=max(prices[i]+next[1]-fee,0+next[0]);
            }
            next=curr;
        }
        return next[1];





        //TABULATION
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));

        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1){
                   dp[i][j]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                }
                else dp[i][j]=max(prices[i]+dp[i+1][1]-fee,0+dp[i+1][0]);
            }
        }
        return dp[0][1];


        // RECURSION AND MEMOIZATION

        // vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return f(prices,0,1,fee,dp);
    }
};