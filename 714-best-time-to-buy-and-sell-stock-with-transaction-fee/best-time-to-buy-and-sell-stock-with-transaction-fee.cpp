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
        // //SPACE OPTIMIZATION
        // // here our curr state is dependent on 2 states next and next to next because it has i+1 and i+2 thats why
        // vector<int> next2(2,0);
        // vector<int> next1(2,0);
        // vector<int> curr(2,0);
        // for(int i=prices.size()-1;i>=0;i--){
        //     for(int j=0;j<2;j++){
        //         if(j==1){
        //            curr[j]=max(-prices[i]+next1[0],0+next1[1]);
        //         }
        //         else curr[j]=max(prices[i]+next2[1],0+next1[0]);
        //     }
        //     next2=next1;
        //     next1=curr;
        // }
        // return next1[1];





        // //TABULATION
        // vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));

        // for(int i=prices.size()-1;i>=0;i--){
        //     for(int j=0;j<2;j++){
        //         if(j==1){
        //            dp[i][j]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
        //         }
        //         else dp[i][j]=max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
        //     }
        // }
        // return dp[0][1];


        // RECURSION AND MEMOIZATION

        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return f(prices,0,1,fee,dp);
    }
};