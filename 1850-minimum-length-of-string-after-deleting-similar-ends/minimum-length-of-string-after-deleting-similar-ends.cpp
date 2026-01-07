class Solution {
public:
    int minimumLength(string s) {
        int a=0; int b=s.size()-1;
        while(s[a]==s[b] && b>a){
            while(s[a]==s[a+1] && b>a) a++;
            while(s[b]==s[b-1] && b>a) b--;

            if(s[a]==s[b]){a++; b--;}
        }
        if(a>b) return 0;
        return b-a+1;
    }
};