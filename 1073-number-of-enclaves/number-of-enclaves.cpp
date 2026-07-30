class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        
        int m=g.size();
        int n=g[0].size();

        vector<vector<int>> v(g.size(),vector<int>(g[0].size(),0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && g[i][j]==1){
                    v[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;

            if(r-1>=0 && v[r-1][c]==0 && g[r-1][c]==1){
                v[r-1][c]=1;
                q.push({r-1,c});
            }
            if(c-1>=0 && v[r][c-1]==0 && g[r][c-1]==1){
                v[r][c-1]=1;
                q.push({r,c-1});
            }
            if(r+1<m && v[r+1][c]==0 && g[r+1][c]==1){
                v[r+1][c]=1;
                q.push({r+1,c});
            }
            if(c+1<n && v[r][c+1]==0 && g[r][c+1]==1){
                v[r][c+1]=1;
                q.push({r,c+1});
            }
        }

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1 && v[i][j]==0) count++;
            }
        }
        return count;
    }
};