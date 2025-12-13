class Solution {
private:
    bool isvalid(vector<vector<char>>& board,int r,int c,int n){
        //ROW
        int count=0;
        for(int i=0;i<9;i++){
            if(n==board[i][c]) count++;
        }
        if(count>1) return false;

        //COLOUMN
        for(int i=0;i<9;i++){
            if(n==board[r][i]) count++;
        }
        if(count>2) return false;

        //BOX
        
        for(int i=(r/3)*3;i<((r/3)*3)+3;i++){
            for(int j=(c/3)*3;j<((c/3)*3)+3;j++){
                if(board[i][j]==n) count++;
            }
        }
        return count==3;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && !isvalid(board,i,j,board[i][j])) return false;
            }
        }
        return true;
    }
};