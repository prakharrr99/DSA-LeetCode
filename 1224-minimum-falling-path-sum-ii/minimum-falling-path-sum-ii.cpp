class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(j<0 || j>=grid[0].size()) return 1e7;
        if(i==0) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];
        
        int val=INT_MAX;
        for(int k=0;k<grid[0].size();k++){
            if(k!=j){
                val=min(val,solve(grid,i-1,k,dp)+grid[i][j]);
            }
        }
        return dp[i][j]=val;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int ans=INT_MAX;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));

        // for(int i=0;i<grid[0].size();i++){
        //     ans=min(ans,solve(grid,grid.size()-1,i,dp));
        // }

        for(int i=0;i<grid[0].size();i++){
            dp[0][i]=grid[0][i];
        }

        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int val=INT_MAX;
                for(int k=0;k<grid[0].size();k++){
                    if(k!=j) val=min(val,dp[i-1][k]+grid[i][j]);
                }

                dp[i][j]=val;
            }
        }

        for(int i=0;i<grid[0].size();i++){
            ans=min(ans,dp[dp.size()-1][i]);
        }
        return ans;
    }
};