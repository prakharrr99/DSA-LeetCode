class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n,vector<int>(n));
        int f=1;
        int sr=0; int sc=0; int er=n-1; int ec=n-1;
        while(sr<=er || sc<=ec){
            for(int i=sc;i<=ec;i++){
                a[sr][i]=f;
                f++;
            }
            sr++;
            for(int i=sr;i<=er;i++){
                a[i][ec]=f;
                f++;
            }
            ec--;
            for(int i=ec;i>=sc;i--){
                a[er][i]=f;
                f++;
            }
            er--;
            for(int i=er;i>=sr;i--){
                a[i][sc]=f;
                f++;
            }
            sc++;
        }
        return a;
    }
};