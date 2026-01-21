class Solution {
public:
    bool detectCapitalUse(string word) {
        int a=0; int b=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z') a=1;
            else if(word[i]>='A' && word[i]<='Z') b=-1;
        }
        if(a==1 && b==0) return true;
        else if(a==0 && b==-1) return true;
        b=0; int c=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z' && i==0) b=-1;
            else if(word[i]>='A' && word[i]<='Z') c=-1;
        }
        if(b==-1 && c==0) return true;
        return false;
    }
};