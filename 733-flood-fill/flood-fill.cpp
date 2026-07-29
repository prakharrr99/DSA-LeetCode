class Solution {
public:
    void bfs(vector<vector<int>>& i,int color,int sr,int sc){
        vector<vector<int>> v(i.size(),vector<int>(i[0].size(),0));
        int c=i[sr][sc];

        queue<pair<int,int>> q;
        q.push({sr,sc});
        v[sr][sc]=1;

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();

            int a=p.first;
            int b=p.second;
            i[a][b]=color;
            if(a-1>=0 && v[a-1][b]==0 && i[a-1][b]==c){
                v[a-1][b]=1;
                q.push({a-1,b});
            }
            if(a+1<i.size() && v[a+1][b]==0 && i[a+1][b]==c){
                v[a+1][b]=1;
                q.push({a+1,b});
            }
            if(b-1>=0 && v[a][b-1]==0 && i[a][b-1]==c){
                v[a][b-1]=1;
                q.push({a,b-1});
            }
            if(b+1<i[0].size() && v[a][b+1]==0 && i[a][b+1]==c){
                v[a][b+1]=1;
                q.push({a,b+1});
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> i=image;

        bfs(i,color,sr,sc);
        return i;
    }
};