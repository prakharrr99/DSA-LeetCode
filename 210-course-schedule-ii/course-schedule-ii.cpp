class Solution {
public:
    void bfs(vector<vector<int>>& g,vector<int>& in,queue<int>& q,vector<int>& t){
        while(!q.empty()){
            int n=q.front();
            q.pop();
            t.push_back(n);
            for(auto it:g[n]){
                if(in[it]!=0){
                    in[it]--;
                    if(in[it]==0) q.push(it);
                }
            }
        }
    }
    vector<int> findOrder(int num, vector<vector<int>>& p) {
        vector<vector<int>> g(num,vector<int>());
        vector<int> in(num,0);

        for(int i=0;i<p.size();i++){
            int u=p[i][1];
            int v=p[i][0];
            g[u].push_back(v);
            in[v]++;
        }

        queue<int> q;

        for(int i=0;i<num;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int> t;
        bfs(g,in,q,t);

        if(t.size()==num) return t;
        return vector<int>();
    }
};