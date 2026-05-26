class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> f(256,0);
        for(int i=0;i<word.size();i++) f[word[i]]++;

        int a=0;
        for(int i=65;i<=90;i++){
            if(f[i]>0 && f[i+32]>0) a++;
        }
        return a;
    }
};