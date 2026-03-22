class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) return true;
        vector<vector<int>> temp(mat.size(),vector<int>(mat[0].size(),0));
        for(int k=1;k<=4;k++){
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    temp[i][j]=mat[mat.size()-1-j][i];
                }
            }
            mat=temp;
            if(temp==target) return true;
        }
        return false;
    }
};