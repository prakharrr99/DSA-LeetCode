class Solution {
public:
    string reverseWords(string s) {

        while(s[0]==' ') s.erase(0,1);
        while(s[s.size()-1]==' ') s.erase(s.size()-1,1);
        
        int sp=0;
        int i=0; int j=1;
        while(j<s.size()){
            if(s[i]==' ' && s[j]==' ') s.erase(j,1);
            else{
                i++; j++;
            }
        }
        reverse(s.begin(),s.end());
        i=0; j=0;
        while(j<s.size()){
            while(j<s.size() && s[j]!=' '){
                j++;
            }
            reverse(s.begin()+i,s.begin()+j);
            j++;
            i=j;
        }
        return s;
    }
};