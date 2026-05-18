class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>>& dp){
        if(j1>=grid[0].size() || j1<0 || j2>=grid[0].size() || j2<0) return -1e7;
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int val=INT_MIN;
        for(int p=-1;p<2;p++){
            for(int q=-1;q<2;q++){
                int temp;
                if(j1!=j2) temp=grid[i][j1]+grid[i][j2];
                else temp=grid[i][j1];
                val=max(val,solve(grid,i+1,j1-p,j2-q,dp)+temp);
            }
        }
        return dp[i][j1][j2]=val;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));

        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==j) dp[grid.size()-1][i][j]=grid[grid.size()-1][i];
                else dp[grid.size()-1][i][j]=grid[grid.size()-1][i]+grid[grid.size()-1][j];
            }
        }

        for(int i=grid.size()-2;i>=0;i--){
            for(int j1=0;j1<grid[0].size();j1++){
                for(int j2=0;j2<grid[0].size();j2++){
                    int val=INT_MIN;
                    for(int p=-1;p<2;p++){
                        if((j1==0 && p==1 ) || (j1==grid[0].size()-1 && p==-1)) continue;
                        for(int q=-1;q<2;q++){
                            if((j2==0 && q==1 ) || (j2==grid[0].size()-1 && q==-1)) continue;
                            int temp=0;
                            if(j1!=j2) temp=grid[i][j1]+grid[i][j2];
                            else temp=grid[i][j1];
                            val=max(val,dp[i+1][j1-p][j2-q]+temp);
                        }
                    }
                    dp[i][j1][j2]=val;
                }
            }
        }
        
        return dp[0][0][grid[0].size()-1];

        return solve(grid,0,0,grid[0].size()-1,dp);
    }
};