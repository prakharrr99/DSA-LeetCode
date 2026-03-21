class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        for(int p=x,q=x+k-1;q>p;p++,q--){
            for(int j=y;j<grid[0].size() && j<y+k;j++){
                swap(grid[p][j],grid[q][j]);
            }
        }
       
        return grid;
    }
};