class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> v(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==(m-1) || j==0 || j==(n-1)) && board[i][j]=='O'){
                    q.push({i,j});
                    v[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            if(r-1>=0 && v[r-1][c]==0 && board[r-1][c]=='O'){
                v[r-1][c]=1;
                q.push({r-1,c});
            }
            if(c-1>=0 && v[r][c-1]==0 && board[r][c-1]=='O'){
                v[r][c-1]=1;
                q.push({r,c-1});
            }
            if(r+1<m && v[r+1][c]==0 && board[r+1][c]=='O'){
                v[r+1][c]=1;
                q.push({r+1,c});
            }
            if(c+1<n && v[r][c+1]==0 && board[r][c+1]=='O'){
                v[r][c+1]=1;
                q.push({r,c+1});
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && v[i][j]==0) board[i][j]='X';
            }
        }

    }
};