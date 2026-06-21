class Solution {
public:
    bool check(vector<vector<char>>& board,int a,int b,char ch){
        int n=board.size();
        for(int r=0;r<n;r++){
            if(board[r][b]==ch && r!=a) return false;
        }
        for(int c=0;c<n;c++){
            if(board[a][c]==ch && c!=b) return false;
        }
        int sr=a/3;
        int sc=b/3;
        if(a/3==0) sr=0;
        else if(a/3==1) sr=3;
        else sr=6;

        if(b/3==0) sc=0;
        else if(b/3==1) sc=3;
        else sc=6;

        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(i==a && j==b) continue;
                if(board[i][j]==ch) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    if(!check(board,i,j,board[i][j])) return false;
                }
            }
        }
        return true;
    }
};