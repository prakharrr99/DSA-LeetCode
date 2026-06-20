class Solution {
public:
    void bfs(int n,int m,vector<vector<int>>& visit,vector<vector<int>>& ans,queue<pair<int,int>>& q){
        while(!q.empty()){
            int r1=q.front().first;
            int c1=q.front().second;

            q.pop();
            if(!visit[r1][c1]){
                visit[r1][c1]=1;
                int co=ans[r1][c1];
                if(r1>0 && visit[r1-1][c1]==0 && ans[r1-1][c1]==0){
                    ans[r1-1][c1]=co;
                    q.push({r1-1,c1});
                }
                if(r1<n-1 && visit[r1+1][c1]==0 && ans[r1+1][c1]==0){
                    ans[r1+1][c1]=co;
                    q.push({r1+1,c1});
                }
                if(c1>0 && visit[r1][c1-1]==0 && ans[r1][c1-1]==0){
                    ans[r1][c1-1]=co;
                    q.push({r1,c1-1});
                }
                if(c1<m-1 && visit[r1][c1+1]==0 && ans[r1][c1+1]==0){
                    ans[r1][c1+1]=co;
                    q.push({r1,c1+1});
                }
            }
        }
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n,vector<int>(m,0));

        auto cmp=[](vector<int>& a,vector<int>& b){
            return a[2]>b[2];
        };
        sort(sources.begin(),sources.end(),cmp);

        queue<pair<int,int>> q;
        for(int i=0;i<sources.size();i++){
            ans[sources[i][0]][sources[i][1]]=sources[i][2];
            q.push({sources[i][0],sources[i][1]});
        }

        vector<vector<int>> visit(n,vector<int>(m,0));
       
       
        bfs(n,m,visit,ans,q);
    
        return ans;
    }
};