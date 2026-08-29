class DSU{
    public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int n){
        if(n==parent[n]) return n;
        return parent[n]=findParent(parent[n]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        DSU ds(m*n);
        vector<int> dx={0,-1,0,1};
        vector<int> dy={-1,0,1,0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int r=i;
                    int c=j;
                    int node=r*n+c;
                    for(int k=0;k<4;k++){
                        int nr=r+dx[k];
                        int nc=c+dy[k];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                            int newnode=nr*n+nc;
                            if(ds.findParent(node)!=ds.findParent(newnode)){
                                ds.unionBySize(node,newnode);
                            }
                        }
                    }
                }
            }
        }
        int ans=*max_element(ds.size.begin(),ds.size.end());
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int r=i;
                    int c=j;
                    int node=r*n+c;
                    unordered_set<int> s;
                    for(int k=0;k<4;k++){
                        int nr=r+dx[k];
                        int nc=c+dy[k];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                            int newnode=nr*n+nc;
                            s.insert(ds.findParent(newnode));
                        }
                    }
                    int temp=0;
                    for(auto it:s){
                        temp+=ds.size[it];
                    }
                    ans=max(ans,temp+1);
                }
            }
        }
        return ans;
    }
};