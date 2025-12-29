class Solution {
    private:
    void row(vector<vector<int>>& matrix,int a){
        for(int i=0;i<matrix[0].size();i++){
            matrix[a][i]=0;
        }
    }
    void col(vector<vector<int>>& matrix,int b){
        for(int i=0;i<matrix.size();i++){
            matrix[i][b]=0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    ans.push_back({i,j});
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            int a=ans[i][0];
            int b=ans[i][1];
            row(matrix,a);
            col(matrix,b);
        }
    }
};