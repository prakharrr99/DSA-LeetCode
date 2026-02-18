class Solution {
public:
    int countBinarySubstrings(string s) {
        
        char p=s[0];
        map<char,int> m;
        m[p]++;
        int a=0;
        int i=1;
        while(i<s.size()){
            m[s[i]]++;
            if(p!=s[i]){
                while(i<s.size() && s[i]==s[i+1]){m[s[i]]++; i++;}
                a=a+min(m['0'],m['1']);
                m[p]=0;
                p=s[i];
            }
            i++;
        }
        a=a+min(m['0'],m['1']);
        return a;
    }
    
};