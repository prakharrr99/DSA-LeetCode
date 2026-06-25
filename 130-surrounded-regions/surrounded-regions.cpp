class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& v,int i,int j){
        v[i][j]=1;
        int m=board.size();
        int n=board[0].size();
        if(i>0 && board[i-1][j]=='O' && !v[i-1][j]){
            dfs(board,v,i-1,j);
        }
        if(i<m-1 && board[i+1][j]=='O' && !v[i+1][j]){
            dfs(board,v,i+1,j);
        }
        if(j>0 && board[i][j-1]=='O' && !v[i][j-1]){
            dfs(board,v,i,j-1);
        }
        if(j<n-1 && board[i][j+1]=='O' && !v[i][j+1]){
            dfs(board,v,i,j+1);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> v(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && (i==0 || i==m-1 || j==0 || j==n-1)){
                    dfs(board,v,i,j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};