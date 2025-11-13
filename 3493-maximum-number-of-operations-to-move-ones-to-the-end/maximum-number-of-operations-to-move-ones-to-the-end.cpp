class Solution {
public:
    int maxOperations(string s) {
        int op=0;
        int c=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='1'){
                c++;
            }
            bool f=true;
            while(s[i]=='0'){
                i++;
                f=false;
            }
            if(f==false){
                op+=c;
                i--;
            }
            i++;
        }
        return op;
    }
};