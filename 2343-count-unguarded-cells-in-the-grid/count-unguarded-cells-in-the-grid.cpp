class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>> grid(m,vector<int>(n,0));

        for(int i=0;i<guards.size();i++){
            int k=guards[i][0];
            int j=guards[i][1];

            grid[k][j]=3;
        }
        for(int i=0;i<walls.size();i++){
            int k=walls[i][0];
            int j=walls[i][1];

            grid[k][j]=2;
        }

        for(int k=0;k<guards.size();k++){
            int i=guards[k][0];
            int j=guards[k][1];

            i=i-1; // otherwise it wont run because it will check guard and condition becomes false
            while(i>=0 && grid[i][j]!=2 && grid[i][j]!=3){
                if(grid[i][j]==0) grid[i][j]=1;
                i--;
            }
            i=guards[k][0];
            i=i+1;
            while(i<m && grid[i][j]!=2 && grid[i][j]!=3){
                if(grid[i][j]==0) grid[i][j]=1;
                i++;
            }
            i=guards[k][0];
            j=j-1;
            while(j>=0 && grid[i][j]!=2 && grid[i][j]!=3){
                if(grid[i][j]==0) grid[i][j]=1;
                j--;
            }
            j=guards[k][1];
            j=j+1;
            while(j<n && grid[i][j]!=2 && grid[i][j]!=3){
                if(grid[i][j]==0) grid[i][j]=1;
                j++;
            }
        }

        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) count++;
            }
        }
        return count;
    }
};