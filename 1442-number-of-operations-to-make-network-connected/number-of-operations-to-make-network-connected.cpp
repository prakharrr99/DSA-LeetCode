class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& v,int node){
        v[node]=1;
        for(auto it:adj[node]){
            if(v[it]==0) dfs(adj,v,it);
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        vector<vector<int>> adj(n);

        if(n-1>c.size()) return -1;

        for(int i=0;i<c.size();i++){
            int u=c[i][0];
            int v=c[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int comp=0;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            if(v[i]==0){
                 dfs(adj,v,i);
                 comp++;
            }
        }
        return comp-1;
    }
};