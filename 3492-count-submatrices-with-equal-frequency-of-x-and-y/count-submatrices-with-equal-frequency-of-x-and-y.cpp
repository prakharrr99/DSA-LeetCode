class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<pair<int,int>>> p(grid.size()+1,vector<pair<int,int>>(grid[0].size()+1,{0,0}));
        
        int ans=0;
        for(int i=1;i<p.size();i++){
            for(int j=1;j<p[0].size();j++){
                if(grid[i-1][j-1]=='X') {
                    p[i][j].first=1+p[i-1][j].first+p[i][j-1].first-p[i-1][j-1].first;
                    p[i][j].second=0+p[i-1][j].second+p[i][j-1].second-p[i-1][j-1].second;
                }
                else if(grid[i-1][j-1]=='Y'){
                    p[i][j].first=0+p[i-1][j].first+p[i][j-1].first-p[i-1][j-1].first;
                    p[i][j].second=1+p[i-1][j].second+p[i][j-1].second-p[i-1][j-1].second;
                }
                else{
                    p[i][j].first=0+p[i-1][j].first+p[i][j-1].first-p[i-1][j-1].first;
                    p[i][j].second=0+p[i-1][j].second+p[i][j-1].second-p[i-1][j-1].second;
                }
                if(p[i][j].first!=0 && p[i][j].first==p[i][j].second) ans++;
            }
        }
        return ans;
    }
};