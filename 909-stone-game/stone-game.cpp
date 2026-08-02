class Solution {
public:
    int f(int i,int j,vector<int>& piles,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(i==j) return piles[i];

        if(dp[i][j]!=-1) return dp[i][j];
        
        int take_i=piles[i]+min(f(i+2,j,piles,dp),f(i+1,j-1,piles,dp));

        int take_j=piles[j]+min(f(i+1,j-1,piles,dp),f(i,j-2,piles,dp));

        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        
        int s=accumulate(piles.begin(),piles.end(),0);

        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        int alice=f(0,piles.size()-1,piles,dp);
        int bob=s-alice;

        return alice>bob;
    }
};