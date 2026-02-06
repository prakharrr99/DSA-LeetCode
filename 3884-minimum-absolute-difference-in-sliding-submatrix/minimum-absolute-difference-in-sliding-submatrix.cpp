class Solution {
public:
    int value(vector<vector<int>>& grid,int a,int b,int k){
        vector<int> temp;
        for(int i=a;i<k+a && i<grid.size();i++){
            for(int j=b;j<k+b && j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
        }
        if(temp.size()!=1LL*k*k) return INT_MAX;
        if(k==1) return 0;
        int m=INT_MAX;
        sort(temp.begin(),temp.end());
        int flag=0;
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i]!=temp[i+1]){
                flag=1;
                m=min(m,abs(temp[i]-temp[i+1]));
            }
        }
        if(flag==0) return 0;
        return m;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans;
        for(int i=0;i<=grid.size()-k;i++){
            vector<int> p;
            for(int j=0;j<=grid[0].size()-k;j++){
                int x=value(grid,i,j,k);
                if(x!=INT_MAX)
                    p.push_back(x);
            }
            if(p.size()!=0)
                ans.push_back(p);
        }
        return ans;
    }
};