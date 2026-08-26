class Solution {
public:
    class DSU{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        unordered_map<string,int> m;
        DSU ds(a.size());

        for(int i=0;i<a.size();i++){
            for(int j=1;j<a[i].size();j++){
                if(m.find(a[i][j])!=m.end()){
                    ds.unionBySize(m[a[i][j]],i);
                }
                else{
                    m[a[i][j]]=i;
                }
            }
        }
        vector<vector<string>> v;
        for(auto it:a){
            v.push_back({it[0]});
        }
        for(auto it:m){
            v[ds.findParent(it.second)].push_back(it.first);
        }
        for(auto& it:v){
            sort(it.begin()+1,it.end());
        }
        vector<vector<string>> ans;
        for(auto it:v){
            if(it.size()>1) ans.push_back(it);
        }
        return ans;
    }
};