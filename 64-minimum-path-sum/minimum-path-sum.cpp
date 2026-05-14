class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(m==0 && n==0) return grid[0][0];
        if(m<0 || n<0) return 1e7;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=min(solve(m-1,n,grid,dp)+grid[m][n],solve(m,n-1,grid,dp)+grid[m][n]);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int left=1e7;
                int up=1e7;
                if(i!=0) left=dp[i-1][j];
                if(j!=0) up=dp[i][j-1];
                dp[i][j]=min(left,up)+grid[i][j];
            }
        }
        return dp[m-1][n-1];
        return solve(m-1,n-1,grid,dp);
    }
};