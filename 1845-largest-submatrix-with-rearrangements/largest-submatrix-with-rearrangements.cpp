class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<int> a(matrix[0].size(),0);
        int area=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    a[j]=0;
                }
                else a[j]+=1;
            }
            vector<int> p=a;
            sort(p.begin(),p.end());
            int c=INT_MAX;
            int n=p.size();
            for(int j=p.size()-1;j>=0;j--){
                c=min(c,p[j]);
                area=max(area,c*(n-j));
            }
        }
        return area;
    }
};