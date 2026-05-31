class Solution {
public:
    int solve(vector<vector<int>>& items, int budget,int i,vector<int>& fact,vector<vector<int>>& dp){
        if(budget==0){
            return 0;
        }
        if(i==0){
            if(budget>=items[0][1]){
                return (budget/items[0][1])+fact[items[0][0]];
            }
            return 0;
        }

        if(dp[i][budget]!=-1) return dp[i][budget];

        int take_f=0;
        int take_same=0;

        if(budget>=items[i][1]) take_same=fact[items[i][0]];

        if(budget>=items[i][1]){
            take_f=solve(items,budget-items[i][1],i-1,fact,dp)+fact[items[i][0]]+1;
            take_same=solve(items,budget-items[i][1],i,fact,dp)+1;
        }
        int no_take=solve(items,budget,i-1,fact,dp);
        return dp[i][budget]=max(max(take_f,no_take),take_same);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        
        vector<int> fact(1501,0);
        
        for(int i=0;i<items.size();i++){
            if(fact[items[i][0]]!=0) continue;
            for(int j=0;j<items.size();j++){
                if(i==j) continue;
                if(items[j][0]%items[i][0]==0) fact[items[i][0]]++;
            }
        }
        vector<vector<int>> dp(items.size(),vector<int>(budget+1,-1));

        return solve(items,budget,items.size()-1,fact,dp);

    }
};