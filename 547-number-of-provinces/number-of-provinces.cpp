class Solution {
public:
    void bfs(vector<vector<int>>& list,int node,vector<int>& visit){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n=q.front();
            q.pop();
            visit[n]=1;
            for(int i=0;i<list[n].size();i++){
                if(visit[list[n][i]]!=1){
                    q.push(list[n][i]);
                    visit[list[n][i]]=1;
                }
                
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visit(isConnected.size()+1,0);
        vector<vector<int>> list(isConnected.size()+1);

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                    if(i==j) continue;
                    list[i+1].push_back(j+1);
                }
            }
        }

        int a=0;
        for(int i=1;i<=isConnected.size();i++){
            if(visit[i]==1) continue;
            a++;
            bfs(list,i,visit);
        }
        return a;
    }
};