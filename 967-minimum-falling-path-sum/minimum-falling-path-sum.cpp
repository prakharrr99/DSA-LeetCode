class Solution {
public:
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(j<0 || j>=matrix[0].size()) return 1e7;
        if(i==0) return matrix[i][j];

        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=min(solve(matrix,i-1,j,dp),min(solve(matrix,i-1,j-1,dp),solve(matrix,i-1,j+1,dp)))+matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));

        // for(int i=0;i<matrix[0].size();i++){
        //     ans=min(ans,solve(matrix,matrix.size()-1,i,dp));
        // }

        for(int i=0;i<matrix[0].size();i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int same=dp[i-1][j]+matrix[i][j];
                int right=INT_MAX;
                int left=INT_MAX;
                if(j!=matrix[0].size()-1) right=dp[i-1][j+1]+matrix[i][j];
                if(j!=0) left=dp[i-1][j-1]+matrix[i][j];
                dp[i][j]=min(same,min(right,left));
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            ans=min(ans,dp[matrix.size()-1][i]);
        }
        return ans;
    }
};