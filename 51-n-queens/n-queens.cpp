class Solution {
public:
    void fun(vector<vector<string>>& a,vector<vector<int>>& board){
        vector<string> temp;
        for(int i=0;i<board.size();i++){
            string s;
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1) s.push_back('Q');
                else s.push_back('.');
            }
            temp.push_back(s);
        }
        a.push_back(temp);
    }
    bool safe(int n,int row,int col,vector<vector<int>>& board){
        int x=row; int y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1) return false;
            x--;y--;
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
    void solve(int n,int col,vector<vector<string>>& a,vector<vector<int>>& board){
        if(col==n){
            fun(a,board); 
            return;
        }
        for(int row=0;row<n;row++){
            if(safe(n,row,col,board)){
                board[row][col]=1;
                solve(n,col+1,a,board);
                board[row][col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> a;
        
        vector<vector<int>> board(n,vector<int>(n,0));

        solve(n,0,a,board);
        return a;
    }
};