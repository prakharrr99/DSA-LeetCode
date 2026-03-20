class Solution {
public:
    
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans;
        for(int i=0;i<grid.size()-k+1;i++){
            vector<int> temp;
            for(int j=0;j<grid[0].size()-k+1;j++){
                vector<int> t;
                for(int a=i;a<i+k;a++){
                    for(int b=j;b<j+k;b++){
                        t.push_back(grid[a][b]);
                    }
                }
                sort(t.begin(),t.end());
                int v=INT_MAX;
                for(int i=0;i<t.size()-1;i++){
                    if(t[i]!=t[i+1]) v=min(v,t[i+1]-t[i]);
                }
                if(v==INT_MAX) v=0;
                temp.push_back(v);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};