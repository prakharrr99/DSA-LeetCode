class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        k=k%mat[0].size();
        vector<vector<int>> a=mat;
        for(int i=0;i<mat.size();i++){
            if(i%2==0){
                for(int j=0;j<mat[0].size();j++){
                    a[i][(j-k+mat[0].size())%mat[0].size()]=mat[i][j];
                }
            }
            else{
                for(int j=0;j<mat[0].size();j++){
                    a[i][(j+k)%mat[0].size()]=mat[i][j];
                }
            }
        }
        return mat==a;
    }
};