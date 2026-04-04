class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols=(encodedText.size()/rows);
        vector<vector<char>> g(rows,vector<char>(cols,' '));
        
        int a=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(a<encodedText.size()) g[i][j]=encodedText[a++];
                else break;
            }
        }

        string ans;
        for(int i=0;i<cols;i++){
            int c=i;
            int r=0;
            while(c<cols && r<rows){
                ans.push_back(g[r++][c++]);
            }
        }
        while(ans.size()>0 && ans[ans.size()-1]==' ') ans.pop_back();
        return ans;
    }
};