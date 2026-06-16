class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> temp=grid;
        int time=0;
        while(true){
            int c=0;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(temp[i][j]==2){
                        if(i>0 && temp[i-1][j]==1){
                            grid[i-1][j]=2;
                            c=1;
                        }
                        if(i<grid.size()-1 && temp[i+1][j]==1){
                            grid[i+1][j]=2;
                            c=1;
                        }
                        if(j>0 && temp[i][j-1]==1){
                            grid[i][j-1]=2;
                            c=1;
                        }
                        if(j<grid[0].size()-1 && temp[i][j+1]==1){
                            grid[i][j+1]=2;
                            c=1;
                        }  
                    }
                }
            }
            if(c==0) break; 
            time++;
            temp=grid;
        }
        for(auto it:grid){
            for(auto iit:it){
                if(iit==1) return -1;
            }
        }
        return time;
    }
};