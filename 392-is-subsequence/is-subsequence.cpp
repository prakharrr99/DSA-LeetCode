class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        
        int i=0; int j=0;
        int a=0;
        while(i<s.size()&& j<t.size()){
            if(s[i]!=t[j]) j++;
            else{
                a++;
                i++; j++;
            }
        }
        return a==s.size();
    }
};