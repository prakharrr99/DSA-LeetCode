class Solution {
public:
    bool safe(int row,int col,int n,vector<vector<int>>& board){
        int x=row; int y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1) return false;
            x--; y--;
        }
        x=row; y=col;
        while(y>=0){
            if(board[x][y]==1) return false;
            y--;
        }
        y=col;
        while(x<n && y>=0){
            if(board[x][y]==1) return false;
            x++; y--;
        }
        return true;
    }
    void solve(int n,int col,int& count,vector<vector<int>>& board){
        if(col==n){
            count++;
            return;
        }
        for(int row=0;row<n;row++){
            if(safe(row,col,n,board)){
                board[row][col]=1;
                solve(n,col+1,count,board);
                board[row][col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        int count=0;
        solve(n,0,count,board);
        return count;
    }
};