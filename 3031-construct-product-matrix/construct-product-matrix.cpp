class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
       // vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),0));
        vector<int> p(grid.size()*grid[0].size(),0);
        vector<int> s(grid.size()*grid[0].size(),0);
        vector<int> temp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
        }
        p[0]=1; s[s.size()-1]=1;
        for(int i=1;i<p.size();i++){
            p[i]=((p[i-1]%12345)*(temp[i-1]%12345))%12345;
        }
        for(int i=s.size()-2;i>=0;i--){
            s[i]=((s[i+1]%12345)*(temp[i+1]%12345))%12345;
        }
        for(int i=0;i<temp.size();i++){
            temp[i]=((p[i]%12345)*(s[i]%12345))%12345;
        }
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),0));
        int a=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans[i][j]=temp[a];
                a++;
            }
        }
        return ans;
    }
};