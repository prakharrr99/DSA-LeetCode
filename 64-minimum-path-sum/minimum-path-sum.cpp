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

        return solve(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};