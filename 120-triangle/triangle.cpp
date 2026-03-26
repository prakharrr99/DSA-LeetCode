class Solution {
public:
    int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        // if(i>=triangle.size() || j>= triangle[i].size()) return INT_MAX; // not required because we will not go out of boundary
        if(i==triangle.size()-1) return triangle[i][j];

        if(dp[i][j]!=-1) return dp[i][j];
        int same_col=triangle[i][j]+solve(triangle,i+1,j,dp);
        int next_col=triangle[i][j]+solve(triangle,i+1,j+1,dp);

        return min(same_col,next_col);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));

        // return solve(triangle,0,0,dp); TLE MEMOIZATION


        //  TABULATION
        // for(int j=0;j<triangle[triangle.size()-1].size();j++){
        //     dp[triangle.size()-1][j]=triangle[triangle.size()-1][j];
        // }

        // for(int i=triangle.size()-2;i>=0;i--){ // is set the base case for n-1 thats why started from n-2
        //     for(int j=triangle[i].size()-1;j>=0;j--){
        //         int same_col=triangle[i][j]+dp[i+1][j];
        //         int next_col=triangle[i][j]+dp[i+1][j+1];
        //         dp[i][j]=min(same_col,next_col);
        //     }
        // }
        // return dp[0][0]; 


        //SPACE OPTIMIZATION

        vector<int> prev(triangle.size(),-1);
        for(int j=0;j<triangle[triangle.size()-1].size();j++){
            prev[j]=triangle[triangle.size()-1][j];
        }

        for(int i=triangle.size()-2;i>=0;i--){ 
            vector<int> cur(triangle.size(),-1);
            for(int j=triangle[i].size()-1;j>=0;j--){
                int same_col=triangle[i][j]+prev[j];
                int next_col=triangle[i][j]+prev[j+1];
                cur[j]=min(same_col,next_col);
            }
            prev=cur;
        }
        return prev[0];
    }
};   