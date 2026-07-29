class Solution {
public:
    void bfs(queue<pair<int,int>>& q,vector<vector<int>>& v,vector<vector<int>>& g,int& t){
        
        while(!q.empty()){
            int s=q.size();
            t++;
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();
                q.pop();
                int a=p.first;
                int b=p.second;
                g[a][b]=2;
                if(a-1>=0 && v[a-1][b]==0 && g[a-1][b]==1){
                    v[a-1][b]=1;
                    q.push({a-1,b});
                }
                if(a+1<g.size() && v[a+1][b]==0 && g[a+1][b]==1){
                    v[a+1][b]=1;
                    q.push({a+1,b});
                }
                if(b-1>=0 && v[a][b-1]==0 && g[a][b-1]==1){
                    v[a][b-1]=1;
                    q.push({a,b-1});
                }
                if(b+1<g[0].size() && v[a][b+1]==0 && g[a][b+1]==1){
                    v[a][b+1]=1;
                    q.push({a,b+1});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> g=grid;

        vector<vector<int>> v(g.size(),vector<int>(g[0].size(),0));

        queue<pair<int,int>> q;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==2 && v[i][j]==0){
                    q.push({i,j});
                    v[i][j]=1; 
                }
            }
        }
        int t=-1;
        bfs(q,v,g,t);

        for(auto it:g){
            for(auto iit:it){
                if(iit==1) return -1;
            }
        }
        if(t==-1) return 0;
        return t;

    }
};