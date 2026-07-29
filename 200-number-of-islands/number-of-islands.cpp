class Solution {
public:
    void f(vector<vector<char>>& grid,vector<vector<int>>& v,int r,int c){
        int n=grid.size();
        int m=grid[0].size();
        if(r-1>=0 && v[r-1][c]==0 && grid[r-1][c]=='1'){
            v[r-1][c]=1;
            f(grid,v,r-1,c);
        }
        if(c-1>=0 && v[r][c-1]==0 && grid[r][c-1]=='1'){
            v[r][c-1]=1;
            f(grid,v,r,c-1);
        }
        if(r+1<n && v[r+1][c]==0 && grid[r+1][c]=='1'){
            v[r+1][c]=1;
            f(grid,v,r+1,c);
        }
        if(c+1<m && v[r][c+1]==0 && grid[r][c+1]=='1'){
            v[r][c+1]=1;
            f(grid,v,r,c+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && v[i][j]==0){
                    c++;
                    v[i][j]=1;
                    f(grid,v,i,j);
                }
            }
        }
        return c;
    }
};