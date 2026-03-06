class Solution {
public:
    bool safe(int v,int row,int col,vector<vector<char>>& board){
        int x=row;
        int y=col;
        int a=0;
        char c=v+'0';
        while(a<board.size()){
            if(board[a][y]==c) return false;
            if(board[x][a]==c) return false;
            a++;
        }
        x=row;
        y=col;
        a=row/3;
        int b=col/3;
        for(int i=a*3;i<a*3+3;i++){
            for(int j=b*3;j<b*3+3;j++){
                if(board[i][j]==c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){

        for(int row=0;row<board.size();row++){
            for(int col=0;col<board.size();col++){
                if(board[row][col]=='.'){
                    for(int i=1;i<=board.size();i++){
                        if(safe(i,row,col,board)){
                            board[row][col]=i+'0';
                            if(solve(board)) return true;
                            else board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};