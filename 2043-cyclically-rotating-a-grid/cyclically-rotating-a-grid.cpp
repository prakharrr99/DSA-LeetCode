class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> mat=grid;
        int m=grid.size();
        int n=grid[0].size();
        for(int p=0;p<min(m,n)/2;p++){
            int x=k%(2*(m-2*p)+2*(n-2-2*p));
            for(int q=1;q<=x;q++){
                //DOWN
                for(int i=p+1;i<m-p;i++){
                    grid[i][p]=mat[i-1][p];
                }
                //L->R
                for(int i=p+1;i<n-p;i++){
                    grid[m-1-p][i]=mat[m-1-p][i-1];
                }
                //up
                for(int i=m-1-p-1;i>=p;i--){
                    grid[i][n-1-p]=mat[i+1][n-1-p];
                }
                //R->L
                for(int i=n-1-p-1;i>=p;i--){
                    grid[p][i]=mat[p][i+1];
                }
                mat=grid;
            }
        }
        return mat;
    }
};