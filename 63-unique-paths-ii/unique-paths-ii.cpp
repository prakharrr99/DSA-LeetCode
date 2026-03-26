class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=solve(obstacleGrid,i-1,j,dp)+solve(obstacleGrid,i,j-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));

        return solve(obstacleGrid,obstacleGrid.size()-1,obstacleGrid[0].size()-1,dp);
    }
};