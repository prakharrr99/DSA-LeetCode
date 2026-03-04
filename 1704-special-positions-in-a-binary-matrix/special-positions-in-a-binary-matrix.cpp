class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    int x=i; int y=j; 
                    bool f=0;
                    int a=0; 
                    int b=0;
                    while(b<mat.size()){
                        if(mat[b][y]==1 && b!=i){
                            f=1;
                            break;
                        }
                        b++;
                    }
                    while(a<mat[0].size()){
                        if(mat[x][a]==1 && a!=y){
                            f=1;
                            break;
                        }
                        a++;
                    }
                    if(f==0) count++;
                }
            }
        }
        return count;
    }
};