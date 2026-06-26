class Solution {
public:
    int f(vector<int>& prices,int i,int buy,int t,int k,vector<vector<vector<int>>>& dp){
        if(t==k) return 0;

        if(i==prices.size()) return 0;

        if(dp[i][buy][t]!=-1) return dp[i][buy][t];
        if(buy){
            return dp[i][buy][t]=max(-prices[i]+f(prices,i+1,0,t,k,dp),0+f(prices,i+1,1,t,k,dp));
        }
        else{
            return dp[i][buy][t]=max(prices[i]+f(prices,i+1,1,t+1,k,dp),0+f(prices,i+1,0,t,k,dp));
        }
        return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));

        // for(int i=0;i<prices.size();i++){
        //     dp[i][1][2]=0;
        //     dp[i][0][2]=0;
        // }
        // dp[prices.size()][1][0]=dp[prices.size()][1][1]=dp[prices.size()][1][2]=0;
        // dp[prices.size()][0][0]=dp[prices.size()][0][1]=dp[prices.size()][0][2]=0;

        // for(int i=prices.size()-1;i>=0;i--){
        //     for(int j=1;j>=0;j--){
        //         for(int k=1;k>=0;k--){

        //             if(j==1) dp[i][j][k]=max(-prices[i]+dp[i+1][0][k],0+dp[i+1][1][k]);
        //             else dp[i][j][k]=max(prices[i]+dp[i+1][1][k+1],0+dp[i+1][0][k]);
        //         }
        //     }
        // }
        // return dp[0][1][0];
        return f(prices,0,1,0,k,dp);
    }
};