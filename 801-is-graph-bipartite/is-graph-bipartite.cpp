class Solution {
public:
    bool bfs(vector<int>& v,vector<vector<int>>& graph,int src){

        queue<int> q;
        q.push(src);
        v[src]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:graph[node]){
                if(v[it]==-1){
                    v[it]=!v[node];
                    q.push(it);
                }
                else if(v[it]==v[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> v(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++){
            if(v[i]==-1){
                if(!bfs(v,graph,i)) return false;
            }
        }
        return true;
    }
};