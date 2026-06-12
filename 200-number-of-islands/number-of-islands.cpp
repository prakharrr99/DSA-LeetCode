class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& v,pair<int,int>& p){
        queue<pair<int,int>> q;
        q.push(p);
        while(!q.empty()){
            pair<int,int> a=q.front();
            q.pop();
            if(a.first>0 && grid[a.first-1][a.second]=='1' && v[a.first-1][a.second]==0){
                q.push({a.first-1,a.second});
                v[a.first-1][a.second]=1;
            }
            if(a.first<grid.size()-1 && grid[a.first+1][a.second]=='1' && v[a.first+1][a.second]==0){
                q.push({a.first+1,a.second});
                v[a.first+1][a.second]=1;
            }
            if(a.second>0 && grid[a.first][a.second-1]=='1' && v[a.first][a.second-1]==0){
                q.push({a.first,a.second-1});
                v[a.first][a.second-1]=1;
            }
            if(a.second<grid[0].size()-1 && grid[a.first][a.second+1]=='1' && v[a.first][a.second+1]==0){
                q.push({a.first,a.second+1});
                v[a.first][a.second+1]=1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> v(grid.size(),vector<int>(grid[0].size(),0));

        int b=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && v[i][j]==0){
                    pair<int,int> a={i,j};
                    bfs(grid,v,a);
                    b++;
                } 
            }
        }
        return b;
    }
};