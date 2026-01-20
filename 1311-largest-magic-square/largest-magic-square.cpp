class Solution {
private:
    bool isvalid(vector<vector<int>>& grid,int i,int j,int m,int n,int k){
        int sum=0;
        if(i + k > m || j + k > n) return false;
        for(int x=i;x<i+k && x<m;x++){
            int s=0;
            for(int y=j;y<j+k;y++) s+=grid[x][y];
            if(x==i) sum=s;
            else if(sum!=s) return false;
        }

        for(int x=j; x<j+k;x++){
            int s=0;
            for(int y=i;y<i+k;y++) s+=grid[y][x];
            if(sum!=s) return false;
        }

        int s=0;
        for(int x=0;x<k;x++){
            s+=grid[x+i][j+x];
        }
        if(s!=sum) return false;

        s=0;

        for (int d=0;d<k;d++) s+=grid[i+d][j+k-1-d];
        if(sum!=s) return false;

        return true;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(); int n=grid[0].size();
        int ans=1;
        for(int k=2;k<=min(m,n);k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(isvalid(grid,i,j,m,n,k)) ans=k;
                }
            }
        }
        return ans;
    }
};