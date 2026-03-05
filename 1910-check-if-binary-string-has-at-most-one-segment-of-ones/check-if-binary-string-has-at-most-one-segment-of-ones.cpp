class Solution {
public:
    bool checkOnesSegment(string s) {
        int a=0; int b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(b==1) return false;
                a=1;
            }
            else{
                if(a==1) b=1;
            }
        }
        // if(b==1) return false;
        return true;
    }
};