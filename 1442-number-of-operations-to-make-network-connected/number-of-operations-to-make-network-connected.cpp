class Solution {
public:
    class DSU{
        vector<int> parent,size;
        public:
        DSU(int n){
            parent.resize(n+1,1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findParent(int n){
            if(parent[n]==n) return n;
            return parent[n]=findParent(parent[n]);
        }
        void unionBySize(int u,int v){
            int ulp_u=findParent(u);
            int ulp_v=findParent(v);
            if(ulp_u==ulp_v) return ;
            if(size[ulp_u]>size[ulp_v]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            else{
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) return -1;
        DSU ds(n);
        for(int i=0;i<connections.size();i++){
            ds.unionBySize(connections[i][0],connections[i][1]);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i) c++;
        }
        return c-1;
    }
};