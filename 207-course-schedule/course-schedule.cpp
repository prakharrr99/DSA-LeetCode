class Solution {
public:
    bool bfs(vector<vector<int>>& g,vector<int>& in,queue<int>& q,int c,int num){

        while(!q.empty()){
            int n=q.front();
            q.pop();
            c++;
            for(auto it:g[n]){
                if(in[it]!=0){
                    in[it]--;
                    if(in[it]==0) q.push(it);
                }
            }
        }
        return c==num;
    }
    bool canFinish(int num, vector<vector<int>>& p) {
        vector<int> in(num,0);

        vector<vector<int>> g(num,vector<int>());
        for(int i=0;i<p.size();i++){
            int u=p[i][1];
            int v=p[i][0];
            g[u].push_back(v);
            in[v]++;
        }

        queue<int> q;
        for(int i=0;i<num;i++){
            if(in[i]==0) q.push(i);
        }
        int c=0;
        return bfs(g,in,q,c,num);
    }
};