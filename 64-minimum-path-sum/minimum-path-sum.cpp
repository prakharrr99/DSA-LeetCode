class Solution {
public:
    long long solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=min(solve(grid,i-1,j,dp)+grid[i][j],solve(grid,i,j-1,dp)+grid[i][j]);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1)); 

        // return solve(grid,grid.size()-1,grid[0].size()-1,dp);

        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=INT_MAX,l=INT_MAX;
                    if(i>0) up=grid[i][j]+dp[i-1][j];
                    if(j>0) l=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(l,up);
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};