class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;int j=matrix.size()*matrix[0].size()-1;
        int col=matrix[0].size();
        int mid=i+(j-i)/2;
        while(j>=i){
            if(matrix[mid/col][mid%col]==target){
                return true;
            }
            else if(matrix[mid/col][mid%col]>target) j=mid-1;
            else i=mid+1;
            mid=i+(j-i)/2;
        }
        return false;
    }
};