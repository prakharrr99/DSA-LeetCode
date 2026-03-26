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

        // MEMOIZATION
        // return solve(obstacleGrid,obstacleGrid.size()-1,obstacleGrid[0].size()-1,dp);

        // TABULATION
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0,l=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) l=dp[i][j-1];
                    dp[i][j]=up+l;
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};