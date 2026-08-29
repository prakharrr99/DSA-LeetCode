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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }

        DSU ds(maxrow+maxcol+1);
        unordered_map<int,int> valid_row_col_with_stones;
        for(auto it:stones){
            int row=it[0];
            int col=it[1]+maxrow+1;
            ds.unionBySize(row,col);
            valid_row_col_with_stones[row]=1;
            valid_row_col_with_stones[col]=1;
        }
        int cnt=0;
        for(auto it:valid_row_col_with_stones){
            if(ds.findParent(it.first)==it.first){
                cnt++;
            }
        }
        return stones.size()-cnt;
    }
};