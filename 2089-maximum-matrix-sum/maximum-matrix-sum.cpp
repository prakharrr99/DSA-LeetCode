class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int a=0;
        int mini=INT_MAX;
        pair<int,int> p;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<0) a++;
                if(abs(matrix[i][j])<mini){
                    mini=abs(matrix[i][j]);
                    p.first=i; p.second=j;
                }
            }
        }
        long long s=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                s+=abs(matrix[i][j]);
            }
        }
        if(a%2==0){
            return s;
        }
        else{
            return s-(2*abs(matrix[p.first][p.second]));
        }
    }
};