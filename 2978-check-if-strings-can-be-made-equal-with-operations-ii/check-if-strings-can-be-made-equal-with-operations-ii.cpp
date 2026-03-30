class Solution {
public:
    bool checkStrings(string s1, string s2) {
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                for(int j=i+2;j<s1.size();j+=2){
                    if(s2[i]==s1[j]){
                        swap(s1[j],s1[i]);
                        break;
                    }
                }
                if(s1[i]!=s2[i]) return false;
            }
        }
        return s1==s2;
    }
};