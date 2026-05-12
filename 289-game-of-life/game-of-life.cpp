class Solution {
public:
    void fun(vector<vector<int>>& board,vector<vector<int>>& bb,int a,int b){
        vector<int> n;

        if(a-1>=0 && b-1>=0) n.push_back(board[a-1][b-1]);
        if(a-1>=0 && b+1<board[0].size()) n.push_back(board[a-1][b+1]);
        if(a-1>=0 && b>=0) n.push_back(board[a-1][b]);
        if(a>=0 && b-1>=0) n.push_back(board[a][b-1]);
        if(a+1<board.size() && b-1>=0) n.push_back(board[a+1][b-1]);
        if(a+1<board.size() && b>=0) n.push_back(board[a+1][b]);
        if(a>=0 && b+1<board[0].size()) n.push_back(board[a][b+1]);
        if(a+1<board.size() && b+1<board[0].size()) n.push_back(board[a+1][b+1]);

        int count=0;
        for(int i=0;i<n.size();i++) count+=n[i];
        if(bb[a][b]==0){
            if(count==3) bb[a][b]=1;
        }
        else{
            if(count>3 || count<2) bb[a][b]=0;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> b=board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                fun(b,board,i,j);
            }
        }
        
    }
};