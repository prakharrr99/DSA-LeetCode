class Solution {
public:
    void bfs(vector<vector<int>>& adj,int node,vector<int>& v){
        queue<int> q;
        q.push(node);
        v[node]=1;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto it:adj[n]){
                if(!v[it]){
                    v[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size(),vector<int>());

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[i].push_back(j);
                }
            }
        }

        int c=0;
        vector<int> v(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            if(!v[i]){
                c++;
                bfs(adj,i,v);
            }
        }
        return c;
    }
};