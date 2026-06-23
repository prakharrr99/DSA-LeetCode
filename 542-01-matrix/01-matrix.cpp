class Solution {
public:
    void bfs(vector<vector<int>>& mat,vector<vector<int>>& v,vector<vector<int>>& dist,queue<pair<int,pair<int,int>>>& q){

        while(!q.empty()){
            pair<int,pair<int,int>> a=q.front();
            q.pop();
            int r=a.second.first;
            int c=a.second.second;
            int d=a.first;
            dist[r][c]=d;
            if(r>0 && !v[r-1][c]){
                v[r-1][c]=1;
                q.push({d+1,{r-1,c}});
            }
            if(r<mat.size()-1 && !v[r+1][c]){
                v[r+1][c]=1;
                q.push({d+1,{r+1,c}});
            }
            if(c>0 && !v[r][c-1]){
                v[r][c-1]=1;
                q.push({d+1,{r,c-1}});
            }
            if(c<mat[0].size()-1 && !v[r][c+1]){
                v[r][c+1]=1;
                q.push({d+1,{r,c+1}});
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,0));
        vector<vector<int>> v(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    v[i][j]=1;
                }
                
            }
        }
        bfs(mat,v,dist,q);
        return dist;
    }
};