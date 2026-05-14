class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==triangle.size()-1) return triangle[i][j];
        if(j>=triangle[i].size()) return 1e7;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=min(solve(i+1,j,triangle,dp)+triangle[i][j],solve(i+1,j+1,triangle,dp)+triangle[i][j]);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));

        for(int i=0;i<triangle.size();i++){
            dp[triangle.size()-1][i]=triangle[triangle.size()-1][i];
        }
        
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                int up=dp[i+1][j]+triangle[i][j];
                int adj=INT_MAX;
                if(j!=triangle[i+1].size()-1) adj=dp[i+1][j+1]+triangle[i][j];
                dp[i][j]=min(up,adj);
            }
        }
        return dp[0][0];
        return solve(0,0,triangle,dp);
    }
};