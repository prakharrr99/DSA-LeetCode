class Solution {
public:
    void bfsatlan(queue<pair<int,int>>& q,vector<vector<int>>& heights,vector<vector<int>>& m){
        int mm=heights.size();
        int n=heights[0].size();
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            
           
            if(r-1>=0 && heights[r-1][c]>=heights[r][c] && m[r-1][c]==0){
                q.push({r-1,c});
                m[r-1][c]=1;
            }
            if(c-1>=0 && heights[r][c-1]>=heights[r][c] && m[r][c-1]==0){
                q.push({r,c-1});
                m[r][c-1]=1;
            }
            if(r+1<mm && heights[r+1][c]>=heights[r][c] && m[r+1][c]==0){
                q.push({r+1,c});
                m[r+1][c]=1;
            }
            if(c+1<n && heights[r][c+1]>=heights[r][c] && m[r][c+1]==0){
                q.push({r,c+1});
                m[r][c+1]=1;
            }
        }
    }
    void bfspaci(queue<pair<int,int>>& q,vector<vector<int>>& heights,vector<vector<int>>& m){
        int mm=heights.size();
        int n=heights[0].size();
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
           
            if(r-1>=0 && heights[r-1][c]>=heights[r][c] && m[r-1][c]!=3 && m[r-1][c]!=2){
                q.push({r-1,c});
                if(m[r-1][c]==1) m[r-1][c]=3;
                else m[r-1][c]=2;
            }
            if(c-1>=0 && heights[r][c-1]>=heights[r][c] && m[r][c-1]!=3 && m[r][c-1]!=2){
                q.push({r,c-1});
                if(m[r][c-1]==1) m[r][c-1]=3;
                else m[r][c-1]=2;
            }
            if(r+1<mm && heights[r+1][c]>=heights[r][c] && m[r+1][c]!=3 && m[r+1][c]!=2){
                q.push({r+1,c});
                if(m[r+1][c]==1) m[r+1][c]=3;
                else m[r+1][c]=2;
            }
            if(c+1<n && heights[r][c+1]>=heights[r][c] && m[r][c+1]!=3 && m[r][c+1]!=2){
                q.push({r,c+1});
                if(m[r][c+1]==1) m[r][c+1]=3;
                else m[r][c+1]=2;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m1=heights.size();
        int n=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> m(m1,vector<int>(n,0));
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        
        for(int i=0;i<m1;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    m[i][j]=1;
                    q1.push({i,j});
                }
            }
        }
        bfsatlan(q1,heights,m);

        for(int i=0;i<m1;i++){
            for(int j=0;j<n;j++){
                if(i==m1-1 || j==n-1){
                    if(m[i][j]==1) m[i][j]=3;
                    else m[i][j]=2;
                    q2.push({i,j});
                }
            }
        }
        bfspaci(q2,heights,m);

        for(int i=0;i<m1;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]==3) ans.push_back({i,j});
            }
        }
        return ans;
    }
};