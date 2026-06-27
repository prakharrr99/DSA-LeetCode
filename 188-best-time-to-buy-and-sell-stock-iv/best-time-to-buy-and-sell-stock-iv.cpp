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
        //FOR RECURSION AND MEMOIZATION
        // vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));


        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int l=k-1;l>=0;l--){
                    if(j==1) dp[i][j][l]=max(-prices[i]+dp[i+1][0][l],0+dp[i+1][1][l]);
                    else dp[i][j][l]=max(prices[i]+dp[i+1][1][l+1],0+dp[i+1][0][l]);
                }
            }
        }
        return dp[0][1][0];
        return f(prices,0,1,0,k,dp);
    }
};