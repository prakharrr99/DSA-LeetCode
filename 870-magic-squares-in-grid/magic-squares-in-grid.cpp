class Solution {
private:
    bool magic(vector<vector<int>>& grid,int row,int col){
        vector<int> a(10,0);

        if(grid[row+1][col+1]!=5) return false;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(grid[i][j]==0 || grid[i][j]>9) return false;
                else a[grid[i][j]]++;
            }
        }
        for(int i=1;i<10;i++){
            if(a[i]!=1) return false;
        }
        if(grid[row][col]+grid[row+1][col]+grid[row+2][col]!=15) return false;
        else if(grid[row][col+1]+grid[row+1][col+1]+grid[row+2][col+1]!=15) return false;
        else if(grid[row][col+2]+grid[row+1][col+2]+grid[row+2][col+2]!=15) return false;
        else if(grid[row][col]+grid[row][col+1]+grid[row][col+2]!=15) return false;
        else if(grid[row+1][col]+grid[row+1][col+1]+grid[row+1][col+2]!=15) return false;
        else if(grid[row+2][col]+grid[row+2][col+1]+grid[row+2][col+2]!=15) return false;
        else if(grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2]!=15) return false;
        else if(grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col]!=15) return false;

        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int a=0;
        if(grid.size()<3 || grid[0].size()<3) return a;
        for(int i=0;i<=grid.size()-3;i++){
            for(int j=0;j<=grid[0].size()-3;j++){
                if(magic(grid,i,j)) a++;
            }
        }
        return a;
    }
};