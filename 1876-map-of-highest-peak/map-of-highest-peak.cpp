class Solution {
public:
    void bfs(queue<pair<int,int>>& q,vector<vector<int>>& v,vector<vector<int>>& g){
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            if(p.first-1>=0 && v[p.first-1][p.second]==0){
                v[p.first-1][p.second]=1;
                q.push({p.first-1,p.second});
                g[p.first-1][p.second]=1+g[p.first][p.second];
            }
            if(p.first+1<g.size() && v[p.first+1][p.second]==0){
                v[p.first+1][p.second]=1;
                q.push({p.first+1,p.second});
                g[p.first+1][p.second]=1+g[p.first][p.second];
            }
            if(p.second-1>=0 && v[p.first][p.second-1]==0){
                v[p.first][p.second-1]=1;
                q.push({p.first,p.second-1});
                g[p.first][p.second-1]=1+g[p.first][p.second];
            }
            if(p.second+1<g[0].size() && v[p.first][p.second+1]==0){
                v[p.first][p.second+1]=1;
                q.push({p.first,p.second+1});
                g[p.first][p.second+1]=1+g[p.first][p.second];
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> g=isWater;

        vector<vector<int>> v(g.size(),vector<int>(g[0].size(),0));

        queue<pair<int,int>> q;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(isWater[i][j]==1){
                    g[i][j]=0;
                    v[i][j]=1;
                    q.push({i,j});
                }
                else g[i][j]=1;
            }
        }

        bfs(q,v,g);
        return g;
    }
};