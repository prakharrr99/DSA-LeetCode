class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> f(256,0);
        int c=0;
        for(int i=0;i<word.size();i++){
            if(f[word[i]]==-1) continue;
            if(word[i]>='A' && word[i]<='Z'){
                if(f[word[i]+32]==0) f[word[i]]=-1;
                if(f[word[i]+32]>0 && f[word[i]]==0){
                    f[word[i]]=1;
                    c++;
                }
            }
            else{
                if(f[word[i]-32]>0){
                    c--;
                    f[word[i]-32]=-1;
                }
                f[word[i]]++;
            }
        }
        return c;
    }
};