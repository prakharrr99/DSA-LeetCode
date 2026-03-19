class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>> p(grid.size()+1,vector<int>(grid[0].size()+1,0));
        for(int i=1;i<p.size();i++){
            for(int j=1;j<p[0].size();j++){
                p[i][j]=grid[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
            }
        }
        // as we are told to include grid[0][0] so after checking prefix only we can increament as it is the sum from 
        int ans=0;
        for(int i=1;i<p.size();i++){
            for(int j=1;j<p[0].size();j++){
                if(p[i][j]<=k) ans++;
            }
        }
        return ans;
    }
};